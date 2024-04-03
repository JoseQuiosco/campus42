import GameBoard from './components/GameBoard.jsx';
import Player from './components/Player.jsx';
import { useState } from 'react';
import Log from './components/Log.jsx';
import { WINNING_COMBINATIONS } from './winning-combinations.js'; 
import GameOver from './components/GameOver.jsx'

const INITIAL_GAME_BOARD = [
  [null, null, null],
  [null, null, null],
  [null, null, null]
];

const PLAYERS = {
  X: 'Player 1',
  O: 'Player 2'
}

function deriveActivePlayer(turns) {
  let currentPlayer = 'X';

  if (turns.length > 0 && turns[0].player === 'X') {
    currentPlayer = 'O';
  }
  return (currentPlayer);
}

function deriveWinner(gameBoard, players) {
  let winner; //let winner = null;
  
  for (const combination of WINNING_COMBINATIONS){
    const firstSymbol = gameBoard[combination[0].row][combination[0].column];
    const secSymbol = gameBoard[combination[1].row][combination[1].column];
    const thirdSymbol = gameBoard[combination[2].row][combination[2].column];

    if (firstSymbol && firstSymbol === secSymbol && firstSymbol===thirdSymbol){
      winner = players[firstSymbol];
      break;
    }
  }
  return winner;
}

function deriveGameBoard(gameTurns) {
  let gameBoard = [...INITIAL_GAME_BOARD.map(array => [...array])];

      for (const turn of gameTurns){
        const {square, player} = turn;
        const {row, col} = square;

        gameBoard[row][col] = player;
      }
    return (gameBoard);
}

function App() {
  const [players, setPlayers] = useState({
    X: 'Player 1',
    Y: 'Player 2'
  });
  const [gameTurns, setGameTurns] = useState([]);
  //const [activePlayer, setActivePlayer] = useState('X');

  const activePlayer = deriveActivePlayer(gameTurns);

  const gameBoard = deriveGameBoard(gameTurns);
  
  const winner = deriveWinner(gameBoard, players);

  function handleSelectPlayer(rowIndex, colIndex) {
    //setActivePlayer((currentActivePlayer) => currentActivePlayer === 'X' ? 'O' : 'X');
    setGameTurns(prevTurns => {
      const currentPlayer = deriveActivePlayer(prevTurns);

      const updatedTurns = [
        { square: { row: rowIndex, col: colIndex }, player: currentPlayer},
          ...prevTurns
      ];

      return updatedTurns;
    });
  }

  function handleRestart() {
    setGameTurns([]);
  }

  function handlePlayerNameChange(symbol, newName) {
    setPlayers(prevPlayers => {
      return (
        {
          ...prevPlayers,
          [symbol]: newName
        }
      );
    })
  }


  return (
    <main>
      <div id="game-container">
        <ol id="players" className='highlight-player'>
          <Player name={PLAYERS.X} symbol="X" isActive={activePlayer === 'X'} onChangeName={handlePlayerNameChange}/>
          <Player name={PLAYERS.O} symbol="O" isActive={activePlayer === 'O'} onChangeName={handlePlayerNameChange}/>
        </ol>
        {(winner || (!winner && gameTurns.length === 9)) && <GameOver winner={winner} onRestart={handleRestart}/>}
        <GameBoard onSelectedSquare={handleSelectPlayer} board={gameBoard}/>
      </div>
      <Log turns={gameTurns}/>
    </main>
  )
}

export default App

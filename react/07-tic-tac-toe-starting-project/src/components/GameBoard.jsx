//import { useState } from 'react';

// const initialGameBoard = [
//     [null, null, null],
//     [null, null, null],
//     [null, null, null]
// ];

//export default function GameBoard({onSelectedSquare, activePlayerSymbol}) {
    // const [gameBoard, setGameBoard] = useState(initialGameBoard);
    
    // function handleSelectSquare(rowIndex, colIndex) {
    //   setGameBoard((prevGameBoard) => {
    //     const updatedBoard = [...prevGameBoard.map(innerArray => [...innerArray])];
    //     updatedBoard[rowIndex][colIndex] = activePlayerSymbol;
    //     return updatedBoard;
    //   });
    //  onSelectedSquare();
        /* 
          Aquí nos aseguramos de hacer una copia profunda del objeto que pasamos por referencia, la modificamos
          y la devolvemos para que la función de estado setee con ese nuevo array... entendí bien?
        */
    //}

    export default function GameBoard({onSelectedSquare, board}) {
      // let gameBoard = initialGameBoard;

      // for (const turn of turns){
      //   const {square, player} = turn;
      //   const {row, col} = square;

      //   gameBoard[row][col] = player;
      // }


    return (
        <ol id="game-board">
          {board.map((row, rowIndex) => (
            <li key={rowIndex}>
              <ol>
                {row.map((playerSymbol, colIndex)=> (
                <li key={colIndex}>
                  <button onClick={() => {onSelectedSquare(rowIndex, colIndex)}} 
                  disabled={playerSymbol !== null}>{playerSymbol}</button>
                </li>
                        ))}
                </ol>
                </li>
            ))}

        </ol>

    );
}
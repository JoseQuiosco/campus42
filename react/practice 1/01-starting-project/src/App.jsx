import Header from './components/Header.jsx';
import UserInput from './components/UserInput.jsx';
import ResultTable from './components/ResultTable.jsx';
import { useState } from 'react';

function App() {

  const [calcParam, setCalcParam] = useState({
    initialInvestment: 0,
    annualInvestment: 0,
    expectedReturn: 0,
    duration: 0
  });


  function handleParams( id, newVal) {
    const newCalcParam = { ...calcParam };
    newCalcParam[id] = newVal;
    setCalcParam(newCalcParam);
  }

  return (
    <>
    <Header />
    <main>
      <UserInput onNewParam={handleParams}/>
      <ResultTable params={{ ...calcParam }}/>
      {/*
        {!inputIsValid && (
        <p className="center">Please enter a duration greater than zero.</p>
        )}
        {inputIsValid && <Results params={{ ...calcParam }} />}

        la historia está en evaluar inputIsValid = duration >= 1 al iniciar. asi nos 
        ahorramos la ventana de InfoMessage y su lógica en ResultTable

      */}
    </main>
  </>
  )
}

export default App

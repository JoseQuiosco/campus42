
import React from "react";
import { calculateInvestmentResults } from '../util/investment.js';
import { formatter } from '../util/investment.js';
import InfoMessage from './InfoMessage';
import { useState , useEffect } from 'react';

export default function ResultTable({ params }) {
    const { initialInvestment, annualInvestment, expectedReturn, duration } = params;
    const [showInfoMessage, setShowInfoMessage] = useState(false);
    
/////////////// COMPROBAMOS si hay que MOSTRAR MENSAJE de duración negativa /////////////////////

    function handleInfoMessage () {
        setShowInfoMessage(false);
    }
    
    useEffect(() => {
        if (duration < 0) {
            setShowInfoMessage(true);
        } else {
            setShowInfoMessage(false);
        }
    }, [duration]);


    if (showInfoMessage) {
        return (
            <InfoMessage onAccord={handleInfoMessage} />
        );
    }

/////////////// SI NO SE MUESTRA MENSAJE cargamos tranquilamente la TABLA /////////////////////

    const dataTable = calculateInvestmentResults({ initialInvestment, annualInvestment, expectedReturn, duration });
    
    function calcTotalInt(dataTable, year) {
        let totalInt = 0;

        for (let i = 0; i < year; i++){
            totalInt += dataTable[i].interest;
        }
        return (totalInt);
    }

    return (
        <>
        <table id="result">
            <thead>
                <tr>
                    <th>Year</th>
                    <th>Investment Value</th>
                    <th>Interest (Year)</th>
                    <th>Total Interest</th>
                    <th>Invested Capital</th>
                </tr>
            </thead>

            <tbody>
                {dataTable.map((dataYear) =>  {
                    let totalInt = calcTotalInt(dataTable, dataYear.year);
                    return (
                        <tr key={dataYear.year}>
                            <td>{dataYear.year}</td>
                            <td>{formatter.format(dataYear.valueEndOfYear)}</td>
                            <td>{formatter.format(dataYear.interest)}</td>
                            <td>{formatter.format(totalInt)}</td>
                            <td>{formatter.format(dataYear.valueEndOfYear - totalInt)}</td>
                        </tr>
                    );}
                )}
            </tbody>
        </table>
        </>
    );
}

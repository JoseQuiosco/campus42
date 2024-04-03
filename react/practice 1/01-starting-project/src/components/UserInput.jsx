
import React from 'react';


export default function UserInput({onNewParam}) {

    function handleInput(event) {
        const value = parseFloat(event.target.value);
        onNewParam(event.target.id, value);
    }

    return (
        <section id="user-input">
            <div className="input-group">
                <div >
                    <label htmlFor="initialInvestment">INITIAL ENVESTMENT</label>
                    <input id="initialInvestment" type="number" required onChange={handleInput}/>
                </div>
                <div>
                    <label htmlFor="annualInvestment">ANNUAL ENVESTMENT</label>
                    <input id="annualInvestment" type="number" required onChange={handleInput}/>
                </div>
            </div>
            <div className="input-group">
                <div>
                    <label htmlFor="expectedReturn">EXPECTED RETURN</label>
                    <input id="expectedReturn" type="number" required onChange={handleInput}/>
                </div>
                <div>
                    <label htmlFor="duration">DURATION</label>
                    <input id="duration" type="number" required onChange={handleInput}/>
                </div>
            </div>
        </section>
    );
}
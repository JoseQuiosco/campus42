import { useState } from 'react';

export default function Player({name, symbol, isActive, onChangeName}) {

    const [playerName, setPlayerName] = useState(name);
    const [isEditing, setIsEditing] = useState(false);

    function handleEdit() {
       /*
        setIsEditing(!isEditing); 
            No hacer cambios de estado así para un estado basado en otro anterior.
            En lugar de usar el valor directamente lo pasamos por una función para que lo gestione. 
            STRONG RECOMENDATION  
       */

        setIsEditing((editing) => !editing);
        if (isEditing) {
            onChangeName(symbol, playerName);
        }
        /*
            De esta forma, React garantiza que siempre vas a estar trabajando al ejecutar la función
            con el último valor de estado disponible y actualizado...
            La sintaxis de la funcion flecha usa editing con el valor actual de la variable de estado.
            Esto es específico en React para la función que gestiona el estado al usar useState!
        */
    }

    function handleChange(event) {
        setPlayerName(event.target.value);  // podemos acceder al elemento donde se produjo el evento con 
                                            // target y al valor del mismo en el momento del click con value.
    /*
        En realidad lo que ocurre es que cada vez que varía algo, cada letra que se borre o escriba, llama 
        a hancleChange que a su vez varía playerName y por lo tanto el contenido de editablePlayerName
    */
    }

    let editablePlayerName = <span className="player-name">{playerName}</span>;
    if (isEditing){
        editablePlayerName = <input type="text" required value={playerName} onChange={handleChange}></input>;
    }

    return (
        <li className={isActive ? 'active' : undefined}>
            <span className="player">
                {editablePlayerName}
                <span className="player-symbol">{symbol}</span>
            </span>
            <button onClick={handleEdit}>{isEditing ? "Save" : "Edit"}</button>
        </li>

    );
    
}
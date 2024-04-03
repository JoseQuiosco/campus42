export default function InfoMessage({onAccord}) {
    return (
        <div id="game-over">
            <h2>Info Message</h2>
            <p>You can't use negative values for duration input!</p>
            <p>
                <button onClick={onAccord}>OK</button>
            </p>
        </div>
    );
}
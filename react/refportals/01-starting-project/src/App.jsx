import Player from "./components/Player.jsx";
import TimeChallenge from "./components/TimeChallenge.jsx";

function App() {
  return (
    <>
      <Player />
      <div id="challenges">
        <TimeChallenge title="Easy" time={1} />
        <TimeChallenge title="Not Easy" time={5} />
        <TimeChallenge title="Getting Tough" time={10} />
        <TimeChallenge title="Pros Only" time={15} />
      </div>
    </>
  );
}

export default App;

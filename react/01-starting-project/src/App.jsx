
import {Fragment} from 'react';
 {/* si usamos <>  y  </>  no hace falta importar Fragment de react*/}
import Header from './components/Header.jsx'
import CoreConcepts from './components/CoreConcepts.jsx';
import Examples from './components/Examples.jsx';



function App() {

  return (
    <Fragment>  {/* podemos usar <>  y  </>  en su lugar, lo acepta React moderno, alternativa a Fragment*/}
      <Header />
      <main>
        <CoreConcepts />
        <Examples />
      </main>
    </Fragment>
  );
}

export default App;

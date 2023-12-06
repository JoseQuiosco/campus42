
1 -> Para sobrecarga de operador =, es el argumento el que tiene que ser const!!
2 -> Lo mismo para el constructor copia.

3 -> En una clase abstracta pura el destructor tiene que ser virtual y al menos un método tiene que ser = 0 (ese también lo ponemos virtual)
4 -> Para clone tener en cuenta que no modifica nada, es const. ASpell *clone(void) const = 0;

5 -> Recuerda que los iteradores son punteros. para acceder a los métodos -> .....

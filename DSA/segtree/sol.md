[LINK](https://www.spoj.com/problems/BRCKTS/)
Es un problema ya que nos condiciona que es con consultas en rango pero no modificando un poco para poder cumplir l oque es la verificacion constante: 
por lo que partimos de un ejemplo simple : 
 
$$
))(( -> [-1,-1,1,1]
$$ 
si tenemos ese ejemplo podemos hacer un prefijo de de  mínimos: 
$$
pref_{sum} = [-1,-2,-1,0]  
$$
$$
pref_{min} = [-1,-2,-2,-2]
$$
si el ultimo de $pref_{sum} = 0$ y el último de $pref_{min} >= 0$  entonces es verdadero 
para llevarlo a un _segment tree_ usamos la formula de prefijos con el mínimo de los hijos izquierdos más la suma de los hijos izquierdos (total) + el minimo de los hijos derechos es decir : 
$$
min_{pref} = min(izq.min_{pref},izq.total + def.min_{pref});
$$
de esta manera y un vez ya probado logramos cumplir todas condiciones para resolver el problema en rangos y consultas en tiempo óptimo. 


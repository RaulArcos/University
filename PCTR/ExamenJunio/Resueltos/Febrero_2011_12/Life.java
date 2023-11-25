import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.locks.*;

public class Life
{
    Random r = new Random(System.nanoTime());
    ReentrantLock l = new ReentrantLock();

    private boolean toro[][] = new boolean[10][10];
    private int nVivas = 50;
    private int colocadas = 0;
    private int x, y, vecinas;

    public Life()
    {
	while(colocadas < 50) {
	    x = r.nextInt(10);
	    y = r.nextInt(10);

	    if(!toro[x][y]) {
		toro[x][y] = true;
		++colocadas;
	    }
	}
    }

    public void nextGen(int fila)
    {
	l.lock();
	try {
	    for(int j = 0; j < 10; ++j){
		vecinas = calcula_vecinas(fila, j);

		if(toro[fila][j] && vecinas < 2) {
                    toro[fila][j] = false;
                    --nVivas;
                }
                else if(toro[fila][j] && vecinas > 3) {
                    toro[fila][j] = false;
                    --nVivas;
                }
                else if(!toro[fila][j] && vecinas == 3) {
                    toro[fila][j] = true;
                    ++nVivas;
		}
	    }
	}finally { l.unlock(); }
    }

    public int status()
    { 
	l.lock();
	try {
	    return nVivas;
	}finally { l.unlock(); }
    }

    public int calcula_vecinas(int f, int j)
    {
	l.lock();
	try {
	    int vecinas = 0;
	    
	    int antX = f - 1;
	    int antY = j - 1;
	    int posX = (f + 1) % 10;
	    int posY = (j + 1) % 10;
	    
	    if(antX == -1)
		antX = 9;
	    if(antY == -1)
		antY = 9;
	    
	    if(toro[antX][j])
		++vecinas;
	    if(toro[f][antY])
		++vecinas;
	    if(toro[antX][antY])
		++vecinas;
	    if(toro[posX][j])
		++vecinas;
	    if(toro[f][posY])
		++vecinas;
	    if(toro[posX][posY])
		++vecinas;
	    if(toro[antX][posY])
		++vecinas;
	    if(toro[posX][antY])
		++vecinas;
	    
	    return vecinas;
	}finally { l.unlock(); }
    }
    
}
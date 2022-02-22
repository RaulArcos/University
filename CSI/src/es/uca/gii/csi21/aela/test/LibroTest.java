package es.uca.gii.csi21.aela.test;

import static org.junit.jupiter.api.Assertions.*;

import java.util.ArrayList;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import es.uca.gii.csi21.aela.data.Data;
import es.uca.gii.csi21.aela.data.Libro;
import es.uca.gii.csi21.aela.data.TipoLibro;

class LibroTest {

	@BeforeAll
	static void setUpBeforeClass() throws Exception {
		Data.LoadDriver();
	}

	@Test
	void testConstructor() throws Throwable {
		int iId = 31;
		Libro libro = new Libro(iId);

		assertEquals(iId, libro.getId());
		assertEquals("El libro del sabio", libro.getTitulo());
		assertEquals("Comedia", libro.getTipoLibro().getNombre());
	}

	@Test
	void testSelect() throws Exception {
		TipoLibro tipoLibro = new TipoLibro(1);
		ArrayList<Libro> aLibro = Libro.Select(null, "Continuacion", tipoLibro.getNombre());
		Libro libro = new Libro(aLibro.get(0).getId());

		assertEquals("La Continuacion de las Aventuras de Diego", libro.getTitulo());
		assertEquals("Drama", libro.getTipoLibro().getNombre());

	}

	@Test
	void testCreate() throws Exception {

		TipoLibro tipoLibro = new TipoLibro(1);
		Libro libro = new Libro();
		libro = Libro.Create("Solo puedes crear este libro una vez", 9.29, tipoLibro);

		ArrayList<Libro> aLibro = Libro.Select(null, "puedes", tipoLibro.getNombre());
		libro = new Libro(aLibro.get(0).getId());

		assertEquals("Solo puedes crear este libro una vez", libro.getTitulo());
		assertEquals("Drama", libro.getTipoLibro().getNombre());
	}

	@Test
	void testDelete() throws Exception {
		Libro libro = new Libro(50);
		libro.Delete();

		assertEquals(libro.getIsDeleted(), true);
	}

}
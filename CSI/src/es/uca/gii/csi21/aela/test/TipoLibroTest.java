package es.uca.gii.csi21.aela.test;

import static org.junit.jupiter.api.Assertions.*;

import java.util.ArrayList;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import es.uca.gii.csi21.aela.data.TipoLibro;

class TipoLibroTest {

	@BeforeAll
	static void setUpBeforeClass() throws Exception {
	}

	@Test
	void testConstructor() throws Throwable {
		int iId_TipoLibro = 1;
		TipoLibro tipoLibro = new TipoLibro(iId_TipoLibro);
		String sNombre = tipoLibro.getNombre();

		assertEquals(tipoLibro.getId(), iId_TipoLibro);
		assertEquals("Drama", sNombre);
	}

	@Test
	void testSelect() throws Throwable {
		ArrayList<TipoLibro> aTipoLibro = TipoLibro.Select();

		assertEquals("Drama", aTipoLibro.get(0).getNombre());
		assertEquals(1, aTipoLibro.get(0).getId());
	}

	@Test
	void testMisc() throws Throwable {
		TipoLibro tipoLibro = new TipoLibro(1);

		assertEquals(tipoLibro.toString(), "1 : Drama");
	}

}

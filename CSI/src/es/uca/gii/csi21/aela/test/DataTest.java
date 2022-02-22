package es.uca.gii.csi21.aela.test;

import static org.junit.jupiter.api.Assertions.*;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;

import es.uca.gii.csi21.aela.data.Data;

class DataTest {

	@BeforeAll
	static void setUpBeforeClass() throws Exception {
		Data.LoadDriver();
	}

	@Disabled
	@Test
	void testTableAccess() throws Throwable {

		Connection con = null;
		ResultSet rs = null;
		int iElementCount = 0;

		try {
			con = Data.Connection();
			rs = con.createStatement().executeQuery("SELECT * FROM libro;");

			while (rs.next())
				iElementCount++;

			// Comprobamos que numero de filas = 9 (Depende de cuantos libros haya a la hora de realizar el test).
			assertEquals(9, iElementCount);
			// Comprobamos que numero de columnas = 3
			assertEquals(3, rs.getMetaData().getColumnCount());
		}

		catch (SQLException e) {
			throw e;
		} finally {
			if (rs != null)
				rs.close();
			if (con != null)
				con.close();
		}
	}

	@Disabled
	@Test
	void testString2Sql() {

		// Comprobamos las combinaciones aportadas en la práctica 1.
		assertEquals(Data.String2Sql("hola", false, false), "hola");
		assertEquals(Data.String2Sql("hola", true, false), "'hola'");
		assertEquals(Data.String2Sql("hola", false, true), "%hola%");
		assertEquals(Data.String2Sql("hola", true, true), "'%hola%'");
		assertEquals(Data.String2Sql("O'Connell", false, false), "O''Connell");
		assertEquals(Data.String2Sql("O'Connell", true, false), "'O''Connell'");
		assertEquals(Data.String2Sql("'Smith '", false, true), "%''Smith ''%");
		assertEquals(Data.String2Sql("'Smith '", true, false), "'''Smith '''");
		assertEquals(Data.String2Sql("'Smith '", true, true), "'%''Smith ''%'");

	}

	@Disabled
	@Test
	void testBoolean2Sql() {
		boolean b = true;
		boolean a = false;

		assertEquals(Data.Boolean2Sql(b), 1);
		assertEquals(Data.Boolean2Sql(a), 0);
	}
}

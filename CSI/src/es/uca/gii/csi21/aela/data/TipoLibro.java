package es.uca.gii.csi21.aela.data;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class TipoLibro {

	private int _iId;
	private String _sNombre;

	// TODO: Preconditions
	public TipoLibro(int iId) throws Exception {
		Connection con = null;
		ResultSet rs = null;
		try {
			con = Data.Connection();
			rs = con.createStatement().executeQuery("SELECT Nombre FROM TipoLibro WHERE id = '" + iId + "' ;");

			rs.next();
			_iId = iId;
			_sNombre = rs.getString("Nombre");

		} catch (SQLException e) {
			throw e;
		} finally {
			if (rs != null)
				rs.close();
			if (con != null)
				con.close();
		}
	}

	/**
	 * 
	 * @category Observers
	 * @precondition El objeto que se quiere observar existe.
	 * @postcondition Devuelve el atributo solicitado.
	 *
	 */
	public int getId() {
		return _iId;
	}

	public String getNombre() {
		return _sNombre;
	}

	/**
	 * 
	 * @category Set
	 * @precondition El objeto al que se quiere cambiar el atributo existe.
	 * @postcondition El valor del atributo pasa a ser el introducido.
	 *
	 */
	public void setTitulo(String sNombre) {
		_sNombre = sNombre;
	}

	/**
	 * 
	 * @category Set
	 * @precondition El objeto al que se quiere cambiar el atributo existe.
	 * @postcondition El valor del atributo pasa a ser el introducido.
	 *
	 */
	public static ArrayList<TipoLibro> Select() throws Exception {
		Connection con = null;
		ResultSet rs = null;
		try {
			con = Data.Connection();

			rs = con.createStatement().executeQuery("SELECT * FROM TipoLibro;");
			ArrayList<TipoLibro> aTipoLibro = new ArrayList<TipoLibro>();

			while (rs.next())
				aTipoLibro.add(new TipoLibro(rs.getInt("Id")));

			return aTipoLibro;

		} catch (SQLException e) {
			throw e;
		} finally {
			if (rs != null)
				rs.close();
			if (con != null)
				con.close();
		}

	}

	/**
	 * 
	 * @precondition
	 * @postcondition
	 * @return
	 *
	 */
	public String toString() {
		return _sNombre;
	}

}

package es.uca.gii.csi21.aela.data;

import java.io.IOException;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Objects;

/**
 * @author 1raul
 *
 */
public class Libro {
	private int _iId;
	private String _sTitulo;
	private double _dPrecio;
	private TipoLibro _tipoLibro;
	private boolean _bIsDeleted;

	/**
	 * 
	 * @precondition
	 * @postcondition
	 * @return
	 *
	 */
	public Libro() {
		_iId = 0;
		_sTitulo = null;
		_dPrecio = 0;
		_tipoLibro = null;
		_bIsDeleted = false;
	}

	// TODO: Preconditions
	public Libro(int iId) throws Exception {
		Connection con = null;
		ResultSet rs = null;

		try {
			con = Data.Connection();
			rs = con.createStatement().executeQuery("SELECT * FROM libro WHERE id = '" + iId + "' ;");

			rs.next();
			_iId = iId;
			_sTitulo = rs.getString("Titulo");
			_dPrecio = rs.getDouble("Precio");
			_tipoLibro = new TipoLibro(rs.getInt("Id_TipoLibro"));
			_bIsDeleted = false;

		} catch (SQLException e) {
			throw e;
		} catch (IOException e) {
			throw e;
		}

		finally {
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

	public double getPrecio() {
		return _dPrecio;
	}

	public String getTitulo() {
		return _sTitulo;
	}

	public TipoLibro getTipoLibro() {
		return _tipoLibro;
	}

	public boolean getIsDeleted() {
		return _bIsDeleted;
	}

	public String toString(Libro Li) {
		return super.toString() + ":" + _sTitulo + ":" + _tipoLibro.getNombre() + ":" + _dPrecio + " €";
	}

	/**
	 * 
	 * @category Set
	 * @precondition El objeto al que se quiere cambiar el atributo existe.
	 * @postcondition El valor del atributo pasa a ser el introducido.
	 *
	 */
	public void setPrecio(double dPrecio) {
		_dPrecio = dPrecio;
	}

	public void setTitulo(String sTitulo) {
		_sTitulo = sTitulo;
	}

	public void setTipoLibro(TipoLibro tipoLibro) {
		_tipoLibro = tipoLibro;
	}

	/**
	 * 
	 * @precondition El objeto al que se quiere cambiar el atributo existe.
	 * @postcondition El valor del atributo pasa a ser el introducido.
	 *
	 */
	public static Libro Create(String sTitulo, double dPrecio, TipoLibro tipoLibro) throws Exception {
		Connection con = null;
		try {
			con = Data.Connection();
			con.createStatement().executeUpdate("INSERT INTO Libro (Id_TipoLibro,Titulo, Precio) VALUES ("
					+ tipoLibro.getId() + ", " + Data.String2Sql(sTitulo, true, false) + ", " + dPrecio + ");");

			return new Libro(Data.LastId(con));
		} catch (SQLException e) {
			throw e;
		} finally {
			if (con != null)
				con.close();
		}
	}

	/**
	 * 
	 * @precondition Existe un objeto libro y NO está eliminado.
	 * @postcondition Marca el libro como eliminado.
	 *
	 */
	public void Delete() throws Exception {

		if (_bIsDeleted == false) {
			Connection con = null;

			try {
				con = Data.Connection();
				con.createStatement().executeUpdate("DELETE FROM Libro WHERE Id = '" + _iId + "';");
				_bIsDeleted = true;
			} catch (SQLException e) {
				throw e;
			} finally {
				if (con != null)
					con.close();
			}
		} else
			throw new Exception("El libro ya está eliminado.");
	}

	// TODO: Preconditions
	/**
	 * 
	 * @precondition
	 * @postcondition
	 * @return
	 *
	 */
	public void Update() throws Exception {
		if (_bIsDeleted == false) {
			Connection con = null;

			try {
				con = Data.Connection();
				con.createStatement()
						.executeUpdate("UPDATE Libro SET Id_TipoLibro = " + _tipoLibro.getId() + ", Titulo = "
								+ Data.String2Sql(_sTitulo, true, false) + ", Precio = " + _dPrecio + " WHERE Id = '"
								+ _iId + "';");
			} catch (SQLException e) {
				throw e;
			} finally {
				if (con != null)
					con.close();
			}
		} else
			throw new Exception("ERROR: El libro está eliminado");
	}

	// TODO: Preconditions
	/**
	 * 
	 * @precondition
	 * @postcondition
	 * @return
	 *
	 */
	public static ArrayList<Libro> Select(Double dPrecio, String sTitulo, String sTipoLibro) throws Exception {
		Connection con = null;
		ResultSet rs = null;
		int iId_TipoLibro = 0;

		ArrayList<TipoLibro> aTipoLibro = TipoLibro.Select();

		for (int i = 0; i < aTipoLibro.size(); i++)
			if (Objects.equals(sTipoLibro, aTipoLibro.get(i).getNombre()))
				iId_TipoLibro = aTipoLibro.get(i).getId();

		con = Data.Connection();

		try {
			rs = con.createStatement().executeQuery("SELECT * FROM Libro " + Where(dPrecio, sTitulo, iId_TipoLibro));
			ArrayList<Libro> aLibro = new ArrayList<Libro>();

			while (rs.next())
				aLibro.add(new Libro(rs.getInt("Id")));

			return aLibro;

		} catch (SQLException e) {
			throw e;
		} finally {
			if (rs != null)
				rs.close();
			if (con != null)
				con.close();
		}

	}

	// TODO: Preconditions
	/**
	 * 
	 * @precondition
	 * @postcondition
	 * @return
	 *
	 */
	private static String Where(Double dPrecio, String sTitulo, int iId_TipoLibro) {
		String sResult = "";
		if (dPrecio != null)
			sResult = "Precio = " + dPrecio + " AND ";
		if (sTitulo != null)
			sResult += "Titulo LIKE " + Data.String2Sql(sTitulo, true, true) + " AND ";
		if (iId_TipoLibro != 0)
			sResult += "Id_TipoLibro = " + iId_TipoLibro + " AND ";
		if (sResult.length() == 0)
			return sResult;
		else
			return "WHERE " + sResult.substring(0, sResult.length() - 5);

	}

}
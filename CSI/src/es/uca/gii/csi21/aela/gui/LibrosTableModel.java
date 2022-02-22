package es.uca.gii.csi21.aela.gui;

import java.util.ArrayList;

import javax.swing.table.AbstractTableModel;

import es.uca.gii.csi21.aela.data.*;

public class LibrosTableModel extends AbstractTableModel {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private ArrayList<Libro> _aData;

	public LibrosTableModel(ArrayList<Libro> aData) {
		_aData = aData;
	}

	public int getColumnCount() {
		return 3;
	}

	public int getRowCount() {
		return _aData.size();
	}

	public Object getValueAt(int iRow, int iCol) {
		Libro libro = _aData.get(iRow);

		switch (iCol) {
		case 0:
			return libro.getTitulo();
		case 1:
			return libro.getPrecio();
		case 2:
			return libro.getTipoLibro();
		}
		return 0;
	}

	public Libro getData(int iRow) {
		return _aData.get(iRow);
	}
}

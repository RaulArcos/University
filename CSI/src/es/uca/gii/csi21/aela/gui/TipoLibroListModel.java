package es.uca.gii.csi21.aela.gui;

import java.util.List;

import javax.swing.AbstractListModel;
import javax.swing.ComboBoxModel;

import es.uca.gii.csi21.aela.data.TipoLibro;

public class TipoLibroListModel extends AbstractListModel<TipoLibro> implements ComboBoxModel<TipoLibro> {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private List<TipoLibro> _aData;
	private Object _oSelectedItem = null;

	public Object getSelectedItem() {
		return _oSelectedItem;
	}

	public void setSelectedItem(Object oSelectedItem) {
		_oSelectedItem = oSelectedItem;
	}

	TipoLibroListModel(List<TipoLibro> aData) {
		_aData = aData;
	}

	public TipoLibro getElementAt(int iRow) {
		TipoLibro tipoLibro = _aData.get(iRow);
		return tipoLibro;
	}

	public TipoLibro getData(int iRow) {
		return _aData.get(iRow);
	}

	public int getSize() {
		return _aData.size();
	}
}

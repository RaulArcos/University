package es.uca.gii.csi21.aela.gui;

import javax.swing.JInternalFrame;
import java.awt.BorderLayout;
import javax.swing.JPanel;
import java.awt.GridLayout;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import java.awt.Container;

import es.uca.gii.csi21.aela.data.Libro;
import es.uca.gii.csi21.aela.data.TipoLibro;

import javax.swing.JButton;
import javax.swing.JTable;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.sql.SQLException;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import javax.swing.JComboBox;

public class IfrLibros extends JInternalFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JTextField txtPrecio;
	private JTextField txtTitulo;
	private JTable tabResult;

	/**
	 * Create the frame.
	 * 
	 * @throws Exception
	 */
	public IfrLibros(Container pnlParent) throws Exception {
		setResizable(true);
		setClosable(true);
		setTitle("Libros");
		setBounds(100, 100, 450, 300);
		getContentPane().setLayout(new BorderLayout(0, 0));

		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.NORTH);
		panel.setLayout(new GridLayout(1, 0, 0, 0));

		JLabel lblTitulo = new JLabel("T\u00EDtulo");
		panel.add(lblTitulo);

		JLabel lblPrecio = new JLabel("Precio");
		panel.add(lblPrecio);

		JLabel lblTipo = new JLabel("Tipo");
		panel.add(lblTipo);

		txtTitulo = new JTextField();
		panel.add(txtTitulo);
		txtTitulo.setColumns(10);

		txtPrecio = new JTextField();
		panel.add(txtPrecio);
		txtPrecio.setColumns(10);

		JComboBox<TipoLibro> cmbTipoLibro = new JComboBox<TipoLibro>();
		cmbTipoLibro.setModel(new TipoLibroListModel(TipoLibro.Select()));
		cmbTipoLibro.setEditable(true);
		panel.add(cmbTipoLibro);

		JButton btnSearch = new JButton("Buscar");
		btnSearch.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {

					Double dPrecio = null;
					String sTitulo = null;
					String stipoLibro = null;

					if (txtPrecio.getText() != null && txtPrecio.getText().length() > 0)
						dPrecio = Double.parseDouble(txtPrecio.getText());
					if (txtTitulo.getText() != null && txtTitulo.getText().length() > 0)
						sTitulo = txtTitulo.getText();
					if (cmbTipoLibro.getSelectedItem() != null)
						if (cmbTipoLibro.getSelectedItem().toString().length() > 0)
							stipoLibro = cmbTipoLibro.getSelectedItem().toString();

					tabResult.setModel(new LibrosTableModel(Libro.Select(dPrecio, sTitulo, stipoLibro)));

				} catch (IOException ex) {
					JOptionPane.showMessageDialog(null, "Ha ocurrido un error durante la lectura", "Input/Output Error",
							JOptionPane.ERROR_MESSAGE);
				} catch (SQLException ex) {
					JOptionPane.showMessageDialog(null, ex.getMessage(), "SQL Error", JOptionPane.ERROR_MESSAGE);
				} catch (NumberFormatException ex) {
					JOptionPane.showMessageDialog(null,
							"Por favor,utilice el formato 'parteentera'.'partedecimal' sin nada detrás.",
							"NumberFormatException", JOptionPane.ERROR_MESSAGE);
				} catch (Exception ex) {
					JOptionPane.showMessageDialog(null, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
				}

			}
		});

		getContentPane().add(btnSearch, BorderLayout.SOUTH);

		tabResult = new JTable();
		tabResult.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				// Se activa con doble clic sobre una fila
				if (e.getClickCount() == 2) {
					int iRow = ((JTable) e.getSource()).getSelectedRow();
					Libro libro = ((LibrosTableModel) tabResult.getModel()).getData(iRow);
					if (libro != null) {
						IfrLibro ifrLibro;
						try {
							ifrLibro = new IfrLibro(libro);
							ifrLibro.setBounds(10, 27, 244, 192);
							pnlParent.add(ifrLibro, 0);
							ifrLibro.setVisible(true);
						} catch (Exception e1) {
							e1.printStackTrace();
						}

					}
				}
			}
		});
		getContentPane().add(tabResult, BorderLayout.CENTER);

	}

}

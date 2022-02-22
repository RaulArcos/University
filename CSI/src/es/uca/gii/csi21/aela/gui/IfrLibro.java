package es.uca.gii.csi21.aela.gui;

import es.uca.gii.csi21.aela.data.*;
import javax.swing.JInternalFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import java.awt.Font;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import java.awt.event.ActionEvent;
import java.io.IOException;
import javax.swing.JComboBox;
import java.awt.Color;

public class IfrLibro extends JInternalFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	private JTextField txtTitulo;
	private Libro _libro = null;
	private JTextField txtPrecio;

	/**
	 * Create the frame.
	 * 
	 * @throws Exception
	 */
	public IfrLibro(Libro libro) throws Exception {

		_libro = libro;
		setResizable(true);
		setClosable(true);
		setTitle("Libro");
		setBounds(100, 100, 450, 300);
		getContentPane().setLayout(null);

		JLabel lblTitulo = new JLabel("TITULO");
		lblTitulo.setFont(new Font("Titillium Web", Font.BOLD, 16));
		lblTitulo.setBounds(10, 10, 62, 24);
		getContentPane().add(lblTitulo);

		txtTitulo = new JTextField();
		txtTitulo.setFont(new Font("Titillium Web", Font.PLAIN, 14));
		txtTitulo.setBounds(10, 47, 418, 24);
		getContentPane().add(txtTitulo);
		txtTitulo.setColumns(10);

		JLabel lblPrecio_1 = new JLabel("PRECIO");
		lblPrecio_1.setFont(new Font("Titillium Web", Font.BOLD, 16));
		lblPrecio_1.setBounds(10, 81, 62, 24);
		getContentPane().add(lblPrecio_1);

		txtPrecio = new JTextField();
		txtPrecio.setBounds(10, 115, 73, 24);
		getContentPane().add(txtPrecio);
		txtPrecio.setColumns(10);

		JComboBox<TipoLibro> cmbTipoLibro = new JComboBox<TipoLibro>();
		cmbTipoLibro.setForeground(new Color(0, 0, 0));
		cmbTipoLibro.setBounds(112, 116, 96, 21);
		getContentPane().add(cmbTipoLibro);
		cmbTipoLibro.setModel(new TipoLibroListModel(TipoLibro.Select()));

		JButton butSave = new JButton("Guardar");

		butSave.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if ((TipoLibro) cmbTipoLibro.getModel().getSelectedItem() != null)
					try {
						if (_libro == null) {
							_libro = Libro.Create(txtTitulo.getText(), Double.parseDouble(txtPrecio.getText()),
									(TipoLibro) cmbTipoLibro.getModel().getSelectedItem());

							JOptionPane.showMessageDialog(null, "¡Libro creado correctamente!");
						} else {

							_libro.setTitulo(txtTitulo.getText());
							_libro.setPrecio(Double.parseDouble(txtPrecio.getText()));
							_libro.setTipoLibro((TipoLibro) cmbTipoLibro.getModel().getSelectedItem());
							_libro.Update();

							JOptionPane.showMessageDialog(null, "¡Libro actualizado correctamente!");
						}

					} catch (NumberFormatException ex) {
						JOptionPane.showMessageDialog(null,
								"Por favor,utilice el formato 'parteentera'.'partedecimal' sin nada detrás.",
								"Formato Numérico Error", JOptionPane.ERROR_MESSAGE);
					} catch (IOException ex) {
						JOptionPane.showMessageDialog(null, ex.getMessage(), "Input/Output Error",
								JOptionPane.ERROR_MESSAGE);
					} catch (SQLException ex) {
						JOptionPane.showMessageDialog(null, ex.getMessage(), "SQL Error", JOptionPane.ERROR_MESSAGE);
					} catch (Exception ex) {
						JOptionPane.showMessageDialog(null, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
					}

				else
					JOptionPane.showMessageDialog(null, "Selecciona un tipo de libro para continuar",
							"Tipo Desconocido", JOptionPane.ERROR_MESSAGE);
			}
		});
		butSave.setFont(new Font("Titillium Web", Font.PLAIN, 14));
		butSave.setBounds(353, 240, 85, 21);
		getContentPane().add(butSave);

		JLabel lblTipo = new JLabel("TIPO");
		lblTipo.setFont(new Font("Titillium Web", Font.BOLD, 16));
		lblTipo.setBounds(112, 81, 62, 24);
		getContentPane().add(lblTipo);

		if (_libro != null) {
			txtTitulo.setText(_libro.getTitulo());
			txtPrecio.setText(Double.toString(_libro.getPrecio()));
			cmbTipoLibro.getModel().setSelectedItem(libro.getTipoLibro());

		}
	}
}

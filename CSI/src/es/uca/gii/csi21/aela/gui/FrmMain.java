package es.uca.gii.csi21.aela.gui;

import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class FrmMain {

	private JFrame frame;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					FrmMain window = new FrmMain();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 * 
	 * @throws UnsupportedLookAndFeelException
	 * @throws IllegalAccessException
	 * @throws InstantiationException
	 * @throws ClassNotFoundException
	 */
	public FrmMain() throws ClassNotFoundException, InstantiationException, IllegalAccessException,
			UnsupportedLookAndFeelException {
		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setTitle("Librer\u00EDa AELA");
		frame.setBounds(200, 200, 600, 400);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		JMenuBar menuBar = new JMenuBar();
		frame.setJMenuBar(menuBar);

		JMenu mitNew = new JMenu("Nuevo");
		menuBar.add(mitNew);

		JMenuItem mitNewLibro = new JMenuItem("Libro");

		mitNewLibro.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				IfrLibro ifrLibro;
				try {
					ifrLibro = new IfrLibro(null);
					ifrLibro.setBounds(10, 27, 450, 300);
					frame.getContentPane().add(ifrLibro, 0);
					ifrLibro.setVisible(true);
				} catch (Exception e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}

			}
		});

		mitNew.add(mitNewLibro);

		JMenu mitSearch = new JMenu("Buscar");
		menuBar.add(mitSearch);

		JMenuItem mitSearchLibro = new JMenuItem("Libro");
		mitSearch.add(mitSearchLibro);

		mitSearchLibro.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				IfrLibros ifrLibros;
				try {
					ifrLibros = new IfrLibros(frame);
					ifrLibros.setBounds(12, 28, 500, 400);
					// El segundo parámetro hace que siempre aparezca delante
					frame.getContentPane().add(ifrLibros, 0);
					ifrLibros.setVisible(true);
				} catch (Exception ex) {
					ex.printStackTrace();
				}

			}
		});

	}

}

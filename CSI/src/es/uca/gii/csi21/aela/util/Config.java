package es.uca.gii.csi21.aela.util;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

public class Config {

	public static Properties Properties(String sFile) throws IOException {

		InputStream inputStream = null;

		try {
			inputStream = new FileInputStream(sFile);
			Properties result = new Properties();
			result.load(inputStream);
			return result;
		} finally {
			if (inputStream != null)
				inputStream.close();
		}
	}
}
package es.uca.gii.csi21.aela.data;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.util.Properties;

import es.uca.gii.csi21.aela.util.Config;
import java.lang.String;

public class Data {

	public static String getPropertiesUrl() {
		return "./db.properties";
	}

	public static Connection Connection() throws Exception {

		try {
			Properties properties = Config.Properties(getPropertiesUrl());
			return DriverManager.getConnection(properties.getProperty("jdbc.url"),
					properties.getProperty("jdbc.username"), properties.getProperty("jdbc.password"));
		} catch (Exception ee) {
			throw ee;
		}
	}

	public static void LoadDriver()
			throws InstantiationException, IllegalAccessException, ClassNotFoundException, IOException {

		Class.forName(Config.Properties(Data.getPropertiesUrl()).getProperty("jdbc.driverClassName")).newInstance();
	}

	// TODO: Preconditions
	public static String String2Sql(String sString, boolean bAddQuotes, boolean bAddWildcards) {
		sString = sString.replace("\'", "\'\'");

		if (bAddQuotes && !bAddWildcards)
			return "'" + sString + "'";

		if (!bAddQuotes && bAddWildcards)
			return "%" + sString + "%";

		if (bAddQuotes && bAddWildcards)
			return "'%" + sString + "%'";

		return sString;
	}

	// TODO: Preconditions
	public static int Boolean2Sql(boolean bBoolean) {
		if (bBoolean)
			return 1;
		else
			return 0;
	}

	// TODO: Preconditions
	public static int LastId(Connection con) throws Exception {
		Properties properties = Config.Properties(getPropertiesUrl());
		ResultSet rs = con.createStatement().executeQuery(properties.getProperty("jdbc.lastIdSentence"));
		rs.next();

		return rs.getInt(1);
	}
}

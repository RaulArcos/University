-- phpMyAdmin SQL Dump
-- version 5.2.0-dev+20211010.2e1971e258
-- https://www.phpmyadmin.net/
--
-- Servidor: localhost
-- Tiempo de generación: 10-01-2022 a las 14:58:26
-- Versión del servidor: 8.0.17
-- Versión de PHP: 8.0.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `aela`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `libro`
--

CREATE TABLE `libro` (
  `Id` int(11) NOT NULL,
  `Id_TipoLibro` int(11) NOT NULL,
  `Titulo` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Precio` double NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Volcado de datos para la tabla `libro`
--

INSERT INTO `libro` (`Id`, `Id_TipoLibro`, `Titulo`, `Precio`) VALUES
(31, 2, 'El libro del sabio', 33.82),
(50, 1, 'La Continuacion de las Aventuras de Diego', 9.29),
(51, 1, 'El libro de prueba mas aburrido de la historia', 1.99),
(53, 3, 'probando', 99.2),
(54, 2, 'EstoyProbando', 99.9);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tipolibro`
--

CREATE TABLE `tipolibro` (
  `Id` int(11) NOT NULL,
  `Nombre` varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Volcado de datos para la tabla `tipolibro`
--

INSERT INTO `tipolibro` (`Id`, `Nombre`) VALUES
(3, 'Aventura'),
(2, 'Comedia'),
(1, 'Drama');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `libro`
--
ALTER TABLE `libro`
  ADD PRIMARY KEY (`Id`),
  ADD UNIQUE KEY `Titulo` (`Titulo`),
  ADD KEY `Id_TipoLibro` (`Id_TipoLibro`);

--
-- Indices de la tabla `tipolibro`
--
ALTER TABLE `tipolibro`
  ADD PRIMARY KEY (`Id`),
  ADD UNIQUE KEY `Nombre` (`Nombre`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `libro`
--
ALTER TABLE `libro`
  MODIFY `Id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=55;

--
-- AUTO_INCREMENT de la tabla `tipolibro`
--
ALTER TABLE `tipolibro`
  MODIFY `Id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `libro`
--
ALTER TABLE `libro`
  ADD CONSTRAINT `libro_ibfk_1` FOREIGN KEY (`Id_TipoLibro`) REFERENCES `tipolibro` (`Id`) ON DELETE RESTRICT ON UPDATE RESTRICT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

-- MySQL dump 10.17  Distrib 10.3.17-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: 127.0.0.1    Database: uca_quiz
-- ------------------------------------------------------
-- Server version	10.4.8-MariaDB-1:10.4.8+maria~bionic

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `uca_quiz`
--

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `uca_quiz` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `uca_quiz`;

--
-- Table structure for table `auth_group`
--

DROP TABLE IF EXISTS `auth_group`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `auth_group` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(150) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_group`
--

LOCK TABLES `auth_group` WRITE;
/*!40000 ALTER TABLE `auth_group` DISABLE KEYS */;
/*!40000 ALTER TABLE `auth_group` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_group_permissions`
--

DROP TABLE IF EXISTS `auth_group_permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `auth_group_permissions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `group_id` int(11) NOT NULL,
  `permission_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `auth_group_permissions_group_id_permission_id_0cd325b0_uniq` (`group_id`,`permission_id`),
  KEY `auth_group_permissio_permission_id_84c5c92e_fk_auth_perm` (`permission_id`),
  CONSTRAINT `auth_group_permissio_permission_id_84c5c92e_fk_auth_perm` FOREIGN KEY (`permission_id`) REFERENCES `auth_permission` (`id`),
  CONSTRAINT `auth_group_permissions_group_id_b120cbf9_fk_auth_group_id` FOREIGN KEY (`group_id`) REFERENCES `auth_group` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_group_permissions`
--

LOCK TABLES `auth_group_permissions` WRITE;
/*!40000 ALTER TABLE `auth_group_permissions` DISABLE KEYS */;
/*!40000 ALTER TABLE `auth_group_permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `auth_permission`
--

DROP TABLE IF EXISTS `auth_permission`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `auth_permission` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `content_type_id` int(11) NOT NULL,
  `codename` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `auth_permission_content_type_id_codename_01ab375a_uniq` (`content_type_id`,`codename`),
  CONSTRAINT `auth_permission_content_type_id_2f476e4b_fk_django_co` FOREIGN KEY (`content_type_id`) REFERENCES `django_content_type` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=49 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `auth_permission`
--

LOCK TABLES `auth_permission` WRITE;
/*!40000 ALTER TABLE `auth_permission` DISABLE KEYS */;
INSERT INTO `auth_permission` VALUES (1,'Can add permission',1,'add_permission'),(2,'Can change permission',1,'change_permission'),(3,'Can delete permission',1,'delete_permission'),(4,'Can view permission',1,'view_permission'),(5,'Can add group',2,'add_group'),(6,'Can change group',2,'change_group'),(7,'Can delete group',2,'delete_group'),(8,'Can view group',2,'view_group'),(9,'Can add content type',3,'add_contenttype'),(10,'Can change content type',3,'change_contenttype'),(11,'Can delete content type',3,'delete_contenttype'),(12,'Can view content type',3,'view_contenttype'),(13,'Can add session',4,'add_session'),(14,'Can change session',4,'change_session'),(15,'Can delete session',4,'delete_session'),(16,'Can view session',4,'view_session'),(17,'Can add user',5,'add_user'),(18,'Can change user',5,'change_user'),(19,'Can delete user',5,'delete_user'),(20,'Can view user',5,'view_user'),(21,'Can add answer',6,'add_answer'),(22,'Can change answer',6,'change_answer'),(23,'Can delete answer',6,'delete_answer'),(24,'Can view answer',6,'view_answer'),(25,'Can add question',7,'add_question'),(26,'Can change question',7,'change_question'),(27,'Can delete question',7,'delete_question'),(28,'Can view question',7,'view_question'),(29,'Can add quiz',8,'add_quiz'),(30,'Can change quiz',8,'change_quiz'),(31,'Can delete quiz',8,'delete_quiz'),(32,'Can view quiz',8,'view_quiz'),(33,'Can add student answer',9,'add_studentanswer'),(34,'Can change student answer',9,'change_studentanswer'),(35,'Can delete student answer',9,'delete_studentanswer'),(36,'Can view student answer',9,'view_studentanswer'),(37,'Can add subject',10,'add_subject'),(38,'Can change subject',10,'change_subject'),(39,'Can delete subject',10,'delete_subject'),(40,'Can view subject',10,'view_subject'),(41,'Can add taken quiz',11,'add_takenquiz'),(42,'Can change taken quiz',11,'change_takenquiz'),(43,'Can delete taken quiz',11,'delete_takenquiz'),(44,'Can view taken quiz',11,'view_takenquiz'),(45,'Can add student',12,'add_student'),(46,'Can change student',12,'change_student'),(47,'Can delete student',12,'delete_student'),(48,'Can view student',12,'view_student');
/*!40000 ALTER TABLE `auth_permission` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `classroom_answer`
--

DROP TABLE IF EXISTS `classroom_answer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `classroom_answer` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `text` varchar(255) NOT NULL,
  `is_correct` tinyint(1) NOT NULL,
  `question_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `classroom_answer_question_id_c6bd564e_fk_classroom_question_id` (`question_id`),
  CONSTRAINT `classroom_answer_question_id_c6bd564e_fk_classroom_question_id` FOREIGN KEY (`question_id`) REFERENCES `classroom_question` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=24 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classroom_answer`
--

LOCK TABLES `classroom_answer` WRITE;
/*!40000 ALTER TABLE `classroom_answer` DISABLE KEYS */;
INSERT INTO `classroom_answer` VALUES (1,'1',0,1),(2,'2',0,1),(3,'3',0,1),(4,'4',1,1),(5,'5',0,1),(6,'8',1,2),(7,'9',0,2),(8,'10',0,2),(9,'60',0,3),(10,'70',0,3),(11,'80',0,3),(12,'90',0,3),(13,'100',1,3),(14,'Azul',0,4),(15,'Verde',0,4),(16,'Blanco',1,4),(17,'Amarillo',0,4),(18,'Violeta',0,4),(19,'Oceanía',0,5),(20,'Europa',0,5),(21,'¿Colón? ¿Ese quién es?',0,5),(22,'África',0,5),(23,'América',1,5);
/*!40000 ALTER TABLE `classroom_answer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `classroom_question`
--

DROP TABLE IF EXISTS `classroom_question`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `classroom_question` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `text` varchar(255) NOT NULL,
  `quiz_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `classroom_question_quiz_id_2a7a64c7_fk_classroom_quiz_id` (`quiz_id`),
  CONSTRAINT `classroom_question_quiz_id_2a7a64c7_fk_classroom_quiz_id` FOREIGN KEY (`quiz_id`) REFERENCES `classroom_quiz` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classroom_question`
--

LOCK TABLES `classroom_question` WRITE;
/*!40000 ALTER TABLE `classroom_question` DISABLE KEYS */;
INSERT INTO `classroom_question` VALUES (1,'¿Cuánto son 2+2?',1),(2,'¿Cuánto son 7+1?',1),(3,'¿Cuánto son 70+30?',2),(4,'¿De qué color era el caballo blanco de Santiago?',2),(5,'¿Qué continente descubrió Colón?',2);
/*!40000 ALTER TABLE `classroom_question` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `classroom_quiz`
--

DROP TABLE IF EXISTS `classroom_quiz`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `classroom_quiz` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `owner_id` int(11) NOT NULL,
  `subject_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `classroom_quiz_owner_id_9ec11b9b_fk_classroom_user_id` (`owner_id`),
  KEY `classroom_quiz_subject_id_1ffd6be8_fk_classroom_subject_id` (`subject_id`),
  CONSTRAINT `classroom_quiz_owner_id_9ec11b9b_fk_classroom_user_id` FOREIGN KEY (`owner_id`) REFERENCES `classroom_user` (`id`),
  CONSTRAINT `classroom_quiz_subject_id_1ffd6be8_fk_classroom_subject_id` FOREIGN KEY (`subject_id`) REFERENCES `classroom_subject` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classroom_quiz`
--

LOCK TABLES `classroom_quiz` WRITE;
/*!40000 ALTER TABLE `classroom_quiz` DISABLE KEYS */;
INSERT INTO `classroom_quiz` VALUES (1,'Examen 1',4,2),(2,'Examen 2',4,5);
/*!40000 ALTER TABLE `classroom_quiz` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `classroom_student`
--

DROP TABLE IF EXISTS `classroom_student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `classroom_student` (
  `user_id` int(11) NOT NULL,
  PRIMARY KEY (`user_id`),
  CONSTRAINT `classroom_student_user_id_3a3bf7a3_fk_classroom_user_id` FOREIGN KEY (`user_id`) REFERENCES `classroom_user` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classroom_student`
--

LOCK TABLES `classroom_student` WRITE;
/*!40000 ALTER TABLE `classroom_student` DISABLE KEYS */;
INSERT INTO `classroom_student` VALUES (2),(3);
/*!40000 ALTER TABLE `classroom_student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `classroom_student_interests`
--

DROP TABLE IF EXISTS `classroom_student_interests`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `classroom_student_interests` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `student_id` int(11) NOT NULL,
  `subject_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `classroom_student_interests_student_id_subject_id_a8e5cda6_uniq` (`student_id`,`subject_id`),
  KEY `classroom_student_in_subject_id_acdf92f5_fk_classroom` (`subject_id`),
  CONSTRAINT `classroom_student_in_student_id_262224bc_fk_classroom` FOREIGN KEY (`student_id`) REFERENCES `classroom_student` (`user_id`),
  CONSTRAINT `classroom_student_in_subject_id_acdf92f5_fk_classroom` FOREIGN KEY (`subject_id`) REFERENCES `classroom_subject` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classroom_student_interests`
--

LOCK TABLES `classroom_student_interests` WRITE;
/*!40000 ALTER TABLE `classroom_student_interests` DISABLE KEYS */;
INSERT INTO `classroom_student_interests` VALUES (1,2,2),(2,2,3),(3,3,1),(4,3,5);
/*!40000 ALTER TABLE `classroom_student_interests` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `classroom_studentanswer`
--

DROP TABLE IF EXISTS `classroom_studentanswer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `classroom_studentanswer` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `answer_id` int(11) NOT NULL,
  `student_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `classroom_studentans_answer_id_049dfa94_fk_classroom` (`answer_id`),
  KEY `classroom_studentans_student_id_435cb2a2_fk_classroom` (`student_id`),
  CONSTRAINT `classroom_studentans_answer_id_049dfa94_fk_classroom` FOREIGN KEY (`answer_id`) REFERENCES `classroom_answer` (`id`),
  CONSTRAINT `classroom_studentans_student_id_435cb2a2_fk_classroom` FOREIGN KEY (`student_id`) REFERENCES `classroom_student` (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classroom_studentanswer`
--

LOCK TABLES `classroom_studentanswer` WRITE;
/*!40000 ALTER TABLE `classroom_studentanswer` DISABLE KEYS */;
INSERT INTO `classroom_studentanswer` VALUES (1,1,2),(2,6,2);
/*!40000 ALTER TABLE `classroom_studentanswer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `classroom_subject`
--

DROP TABLE IF EXISTS `classroom_subject`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `classroom_subject` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(30) NOT NULL,
  `color` varchar(7) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classroom_subject`
--

LOCK TABLES `classroom_subject` WRITE;
/*!40000 ALTER TABLE `classroom_subject` DISABLE KEYS */;
INSERT INTO `classroom_subject` VALUES (1,'Arts','#343a40'),(2,'Computing','#007bff'),(3,'Math','#28a745'),(4,'Biology','#17a2b8'),(5,'History','#ffc107');
/*!40000 ALTER TABLE `classroom_subject` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `classroom_takenquiz`
--

DROP TABLE IF EXISTS `classroom_takenquiz`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `classroom_takenquiz` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `score` double NOT NULL,
  `date` datetime(6) NOT NULL,
  `quiz_id` int(11) NOT NULL,
  `student_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `classroom_takenquiz_quiz_id_e83e738b_fk_classroom_quiz_id` (`quiz_id`),
  KEY `classroom_takenquiz_student_id_c543e3f2_fk_classroom` (`student_id`),
  CONSTRAINT `classroom_takenquiz_quiz_id_e83e738b_fk_classroom_quiz_id` FOREIGN KEY (`quiz_id`) REFERENCES `classroom_quiz` (`id`),
  CONSTRAINT `classroom_takenquiz_student_id_c543e3f2_fk_classroom` FOREIGN KEY (`student_id`) REFERENCES `classroom_student` (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classroom_takenquiz`
--

LOCK TABLES `classroom_takenquiz` WRITE;
/*!40000 ALTER TABLE `classroom_takenquiz` DISABLE KEYS */;
INSERT INTO `classroom_takenquiz` VALUES (1,50,'2019-10-12 15:31:03.099000',1,2);
/*!40000 ALTER TABLE `classroom_takenquiz` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `classroom_user`
--

DROP TABLE IF EXISTS `classroom_user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `classroom_user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `password` varchar(128) NOT NULL,
  `last_login` datetime(6) DEFAULT NULL,
  `is_superuser` tinyint(1) NOT NULL,
  `username` varchar(150) NOT NULL,
  `first_name` varchar(30) NOT NULL,
  `last_name` varchar(150) NOT NULL,
  `email` varchar(254) NOT NULL,
  `is_staff` tinyint(1) NOT NULL,
  `is_active` tinyint(1) NOT NULL,
  `date_joined` datetime(6) NOT NULL,
  `is_student` tinyint(1) NOT NULL,
  `is_teacher` tinyint(1) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classroom_user`
--

LOCK TABLES `classroom_user` WRITE;
/*!40000 ALTER TABLE `classroom_user` DISABLE KEYS */;
INSERT INTO `classroom_user` VALUES (2,'pbkdf2_sha256$150000$lvnygN2BieeJ$AnOnn1jLdJuRdfwm1mbyzhcDf+4ttjFhHioZT90csAo=','2019-10-12 19:49:31.908587',0,'student1','','','',0,1,'2019-10-12 15:28:53.844000',1,0),(3,'pbkdf2_sha256$150000$y97jHLVtzIn8$clr9NW8LlIj/WTt8a6FMXvjbK4lndIDaxZcamyJxYI4=','2019-10-12 19:52:27.078754',0,'student2','','','',0,1,'2019-10-12 15:29:05.500000',1,0),(4,'pbkdf2_sha256$150000$iG5Ya1hqVk8C$BnLd5hFHSLTE6GAXLJvRHINonUmPelKr/XqEr6Rt2ko=','2019-10-12 19:49:47.878897',0,'teacher1','','','',0,1,'2019-10-12 15:29:15.206000',0,1);
/*!40000 ALTER TABLE `classroom_user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `classroom_user_groups`
--

DROP TABLE IF EXISTS `classroom_user_groups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `classroom_user_groups` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `group_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `classroom_user_groups_user_id_group_id_cb852cf0_uniq` (`user_id`,`group_id`),
  KEY `classroom_user_groups_group_id_b5028fea_fk_auth_group_id` (`group_id`),
  CONSTRAINT `classroom_user_groups_group_id_b5028fea_fk_auth_group_id` FOREIGN KEY (`group_id`) REFERENCES `auth_group` (`id`),
  CONSTRAINT `classroom_user_groups_user_id_70bae1b0_fk_classroom_user_id` FOREIGN KEY (`user_id`) REFERENCES `classroom_user` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classroom_user_groups`
--

LOCK TABLES `classroom_user_groups` WRITE;
/*!40000 ALTER TABLE `classroom_user_groups` DISABLE KEYS */;
/*!40000 ALTER TABLE `classroom_user_groups` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `classroom_user_user_permissions`
--

DROP TABLE IF EXISTS `classroom_user_user_permissions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `classroom_user_user_permissions` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `permission_id` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `classroom_user_user_perm_user_id_permission_id_37c329f2_uniq` (`user_id`,`permission_id`),
  KEY `classroom_user_user__permission_id_ccaa6935_fk_auth_perm` (`permission_id`),
  CONSTRAINT `classroom_user_user__permission_id_ccaa6935_fk_auth_perm` FOREIGN KEY (`permission_id`) REFERENCES `auth_permission` (`id`),
  CONSTRAINT `classroom_user_user__user_id_fc6f1134_fk_classroom` FOREIGN KEY (`user_id`) REFERENCES `classroom_user` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `classroom_user_user_permissions`
--

LOCK TABLES `classroom_user_user_permissions` WRITE;
/*!40000 ALTER TABLE `classroom_user_user_permissions` DISABLE KEYS */;
/*!40000 ALTER TABLE `classroom_user_user_permissions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `django_content_type`
--

DROP TABLE IF EXISTS `django_content_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `django_content_type` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `app_label` varchar(100) NOT NULL,
  `model` varchar(100) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `django_content_type_app_label_model_76bd3d3b_uniq` (`app_label`,`model`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `django_content_type`
--

LOCK TABLES `django_content_type` WRITE;
/*!40000 ALTER TABLE `django_content_type` DISABLE KEYS */;
INSERT INTO `django_content_type` VALUES (2,'auth','group'),(1,'auth','permission'),(6,'classroom','answer'),(7,'classroom','question'),(8,'classroom','quiz'),(12,'classroom','student'),(9,'classroom','studentanswer'),(10,'classroom','subject'),(11,'classroom','takenquiz'),(5,'classroom','user'),(3,'contenttypes','contenttype'),(4,'sessions','session');
/*!40000 ALTER TABLE `django_content_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `django_migrations`
--

DROP TABLE IF EXISTS `django_migrations`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `django_migrations` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `app` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `applied` datetime(6) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `django_migrations`
--

LOCK TABLES `django_migrations` WRITE;
/*!40000 ALTER TABLE `django_migrations` DISABLE KEYS */;
INSERT INTO `django_migrations` VALUES (1,'contenttypes','0001_initial','2019-10-12 19:48:35.083553'),(2,'contenttypes','0002_remove_content_type_name','2019-10-12 19:48:35.168767'),(3,'auth','0001_initial','2019-10-12 19:48:35.276869'),(4,'auth','0002_alter_permission_name_max_length','2019-10-12 19:48:35.656837'),(5,'auth','0003_alter_user_email_max_length','2019-10-12 19:48:35.674966'),(6,'auth','0004_alter_user_username_opts','2019-10-12 19:48:35.693439'),(7,'auth','0005_alter_user_last_login_null','2019-10-12 19:48:35.709937'),(8,'auth','0006_require_contenttypes_0002','2019-10-12 19:48:35.714627'),(9,'auth','0007_alter_validators_add_error_messages','2019-10-12 19:48:35.725222'),(10,'auth','0008_alter_user_username_max_length','2019-10-12 19:48:35.735825'),(11,'auth','0009_alter_user_last_name_max_length','2019-10-12 19:48:35.744239'),(12,'auth','0010_alter_group_name_max_length','2019-10-12 19:48:35.803495'),(13,'auth','0011_update_proxy_permissions','2019-10-12 19:48:35.822571'),(14,'classroom','0001_initial','2019-10-12 19:48:36.302206'),(15,'classroom','0002_create_initial_subjects','2019-10-12 19:48:37.365210'),(16,'sessions','0001_initial','2019-10-12 19:48:37.392872');
/*!40000 ALTER TABLE `django_migrations` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `django_session`
--

DROP TABLE IF EXISTS `django_session`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `django_session` (
  `session_key` varchar(40) NOT NULL,
  `session_data` longtext NOT NULL,
  `expire_date` datetime(6) NOT NULL,
  PRIMARY KEY (`session_key`),
  KEY `django_session_expire_date_a5c62663` (`expire_date`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `django_session`
--

LOCK TABLES `django_session` WRITE;
/*!40000 ALTER TABLE `django_session` DISABLE KEYS */;
/*!40000 ALTER TABLE `django_session` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-10-12 21:55:59
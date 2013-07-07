CREATE DATABASE IF NOT EXISTS `text` DEFAULT CHARACTER SET utf8 ;

USE `text` ;

-- -----------------------------------------------------

-- Table `text`.`user`

-- -----------------------------------------------------

CREATE  TABLE IF NOT EXISTS `text`.`user` (

  `id` INT NOT NULL AUTO_INCREMENT ,

  `name` VARCHAR(45) NOT NULL ,

  `password` VARCHAR(45) NOT NULL ,

  `gender` TINYINT NULL DEFAULT 1 ,

  `birthdate` VARCHAR(45) NULL DEFAULT NULL ,

  `question` VARCHAR(45) NULL DEFAULT NULL ,

  `answer` VARCHAR(45) NULL DEFAULT NULL ,

  `adress` VARCHAR(45) NULL DEFAULT NULL ,

  `phone` VARCHAR(45) NULL DEFAULT NULL ,

  `email` VARCHAR(45) NOT NULL ,

  `regdate` TIMESTAMP NOT NULL ,

  UNIQUE INDEX `id_UNIQUE` (`id` ASC) ,

  PRIMARY KEY (`id`) ,

  UNIQUE INDEX `name_UNIQUE` (`name` ASC) ,

  UNIQUE INDEX `email_UNIQUE` (`email` ASC) )

ENGINE = MyISAM

DEFAULT CHARACTER SET = utf8;

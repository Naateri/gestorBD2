# Gestor Base de Datos II

Sintaxis del gestor:

## Tipos de dato:

- INTEGER
- VARCHAR(N)

## Creación de tablas:

 >CREAR TABLA nombre_tabla tipo_de_dato nombre_dato ;

## Inserción de datos:

 >INSERTAR EN nombre_tabla VALORES valor_1 valor_2 ;

## Selección de datos:

 >SELECT * FROM nombre_tabla (WHERE atributo = valor) ;

## Borrado de datos:

 >DELETE FROM nombre_tabla WHERE atributo = valor ;

## Actualización de datos:

 >UPDATE nombre_tabla SET atributo = valor WHERE atributo = valor ;

## Inserción de múltiples datos:

 >INSERTAR VARIOS EN nombre_tabla I/Rnum1,num2/C ;

I: incrementador.
Rnum1,num2: Aleatorio entre num1 y num2 (ambos números).
C: Caracter (nombre_campo + I)

Se ponen tantas letras como campos haya.

####NO OLVIDARSE DE PONER ESPACIO ; LUEGO DE CADA SENTENCIA

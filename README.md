# Gestor Base de Datos II
(No le hagan caso a Juan)

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

## Mandar árbol a ram:

  >A RAM (indice.idx);

## Crear índice:

  >CREATE INDEX index_name ON table (column) ;

## Usar índice en consulta SELECT

  >SELECT * FROM tabla WHERE columna = valor IDX = index.idx ;

## Actualizar índices
  >INSERTAR CON INDICE EN nombre-tabla VALORES value-1 value-2 ... value-n INDICE index1-name.idx(column) index2-name.idx(column) S(CurrentMaxRow+1) ;

Donde luego de VALORES van todos los valores a ser insertados, luego de INDICE el nombre del índice indicando que columna es (contando desde 0, ej: si la tabla tiene las columnas "id, nombre, apellido, edad" sería id.idx(0) edad.idx(3)), y CurrentMaxRow+1 la fila que sigue (ej: si hay 1000 filas en su tabla, tendría que poner S1001).

  >ELIMINAR CON INDICE EN nombre-tabla WHERE atributo = valor INDICE indice-a-actualizar.idx ;

  >UPDATE CON INDICE EN nombre-tabla SET atributo = valor WHERE atributo = valor INDICE indice-a-actualizar.idx ;

Es importante que los indices a actualizar estén cargados en ram (A RAM), si no, no se podrán apreciar los efectos de las consultas.

(Nota: con las tablas grandes, no funciona con los índices de id's)

### NO OLVIDARSE DE PONER ESPACIO ; LUEGO DE CADA SENTENCIA EXCEPTO A RAM

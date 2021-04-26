## **Tarea 2: Rastreador de "System Calls"**
Del curso Sistema Operativos Avanzados, de la Maestría de Ciencias de la Computación del Tecnológico de Costa Rica.

##### Equipo de trabajo:
- Carvajal Barboza Nicole
- Gonzáles Villanueva Ruben
- López Díaz Edisson
- Mena Kikut Otto
- Soto Rojas Cristina


# Uso del programa

#### Compilación
Se utiliza el compilador de GNU, el GCC, usando la siguiente línea:

`gcc main.c -o rastreador

- **main.c**: Nombre del archivo principal.
- **-o**: Indica el nombre del archivo de salida.
- **rastreador**: Nombre del archivo de salida.

#### Ejecución

Se usa el archivo de salida resultante de la compilación "**rastreador**". Para ejecutarlo tenemos las siguiente sintaxis:

`./rastreador [opciones rastreador] Prog [opciones de Prog]`

En donde las opciones válidas para rastreador son:

- -v desplegará un mensaje cada vez que detecte un System Call de Prog .
- -V será idéntico a la opción -v , pero hace una pausa hasta que el usuario presione cualquier tecla para
continuar la ejecución de Prog.

Y las opciones de Prog son los parámetros del programa Prog.

Nota: para ejecutar un programa propio Prog debe incluir el path del programa.


# No funcional en el programa
Actualmente **todo funciona en el programa y se programó tal como se solicitó en el enunciado**.

<br /><br /><br />



-------------
# Otros
## Ejecuciones del programa
A continuación dos ejecuciones del programa, mostrando el comando de ejecución y las líneas impresas en consola del resultado. Para ejemplificar se utilizó el programa adjunto llamado hora que imprime la hora del sistema y el ejecutable echo del sistema.

### Caso -v
Ejecución:
`./rastreador -v /home/user/Documents/SOA/hora`

Resultado:
```c
Seleccionó opción v
El nombre del programa por ejecutar es: /home/user/Documents/SOA/hora
Se ejecutara programa en modo: 1
Programa realizó system call execve(59) llamado con 0, 0, 0
Programa realizó system call brk(12) llamado con 1, 140390765518507, 95
Programa realizó system call arch_prctl(158) llamado con 0, 140390765513557, 140390765511216
Programa realizó system call access(21) llamado con 140390765588832, 140390765522267, 140390765396592
Programa realizó system call openat(257) llamado con 140390765588680, 140390765522632, 524288
Programa realizó system call fstat(5) llamado con 140390765588680, 140390765522073, 140735949784208
Programa realizó system call mmap(9) llamado con 2, 140390765523174, 1
Programa realizó system call close(3) llamado con 140390765588680, 140390765522315, 1
Programa realizó system call openat(257) llamado con 140735949784607, 140390765522632, 524288
Programa realizó system call read(0) llamado con 140735949784607, 140390765522824, 832
Programa realizó system call pread64(17) llamado con 784, 140390765522878, 784
Programa realizó system call pread64(17) llamado con 140735949784024, 140390765522878, 32
Programa realizó system call pread64(17) llamado con 140735949784080, 140390765522878, 68
Programa realizó system call fstat(5) llamado con 0, 140390765522073, 140735949784288
Programa realizó system call mmap(9) llamado con 34, 140390765523174, 3
Programa realizó system call pread64(17) llamado con 784, 140390765522878, 784
Programa realizó system call pread64(17) llamado con 140735949782544, 140390765522878, 32
Programa realizó system call pread64(17) llamado con 140735949782512, 140390765522878, 68
Programa realizó system call mmap(9) llamado con 2050, 140390765523174, 1
Programa realizó system call mprotect(10) llamado con 0, 140390765523355, 0
Programa realizó system call mmap(9) llamado con 2066, 140390765523174, 5
Programa realizó system call mmap(9) llamado con 2066, 140390765523174, 1
Programa realizó system call mmap(9) llamado con 2066, 140390765523174, 3
Programa realizó system call mmap(9) llamado con 50, 140390765523174, 3
Programa realizó system call close(3) llamado con 1879047679, 140390765522315, 0
Programa realizó system call arch_prctl(158) llamado con 1, 140390765403328, -140390765272688
Programa realizó system call mprotect(10) llamado con 140390763374912, 140390765523355, 1
Programa realizó system call mprotect(10) llamado con 0, 140390765523355, 1
Programa realizó system call mprotect(10) llamado con 0, 140390765523355, 1
Programa realizó system call munmap(11) llamado con 140390765588832, 140390765523307, 56255481643008
Programa realizó system call brk(12) llamado con 135168, 140390764368875, 688
Programa realizó system call brk(12) llamado con 135168, 140390764368875, 140390765253376
Programa realizó system call openat(257) llamado con 94796062876352, 140390764365404, 524288
Programa realizó system call fstat(5) llamado con 0, 140390764340873, 140735949787408
Programa realizó system call fstat(5) llamado con 140390765245600, 140390764340873, 140735949786944
Programa realizó system call read(0) llamado con 94796062876352, 140390764365672, 4096
Programa realizó system call lseek(8) llamado con 3432, 140390764343931, 1
Programa realizó system call read(0) llamado con 94796062876352, 140390764365672, 4096
Programa realizó system call close(3) llamado con 94796062876352, 140390764364971, 140390765242528
Programa realizó system call fstat(5) llamado con 140390765245600, 140390764340873, 140735949785776
La hora es: Mon Apr 26 15:14:37 2021
Programa realizó system call write(1) llamado con 37, 140390764343783, 37

ID	║ CONT	║ NOMBRE
══════════════════════════
0	║ 3	║ close
1	║ 1	║ write
3	║ 3	║ close
5	║ 5	║ fstat
8	║ 1	║ write
9	║ 7	║ poll
10	║ 4	║ stat
11	║ 1	║ write
12	║ 3	║ close
17	║ 6	║ lstat
21	║ 1	║ write
59	║ 1	║ write
158	║ 2	║ open
257	║ 3	║ close

```

### Caso 2
Ejecución:
`./rastreador -V /home/user/Documents/SOA/hora`

Resultado:
```c
Seleccionó opción V
El nombre del programa por ejecutar es: /home/user/Documents/SOA/hora
Se ejecutara programa en modo: 2
Programa realizó system call execve(59) llamado con 0, 0, 0
Presione cualquier tecla para continuar.
Programa realizó system call brk(12) llamado con 1, 139785173323435, 95
Presione cualquier tecla para continuar.
Programa realizó system call arch_prctl(158) llamado con 0, 139785173318485, 139785173316144
Presione cualquier tecla para continuar.
Programa realizó system call access(21) llamado con 139785173393760, 139785173327195, 139785173201520
Presione cualquier tecla para continuar.
Programa realizó system call openat(257) llamado con 139785173393608, 139785173327560, 524288
Presione cualquier tecla para continuar.
Programa realizó system call fstat(5) llamado con 139785173393608, 139785173327001, 140726234330640
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 2, 139785173328102, 1
Presione cualquier tecla para continuar.
Programa realizó system call close(3) llamado con 139785173393608, 139785173327243, 1
Presione cualquier tecla para continuar.
Programa realizó system call openat(257) llamado con 140726234331039, 139785173327560, 524288
Presione cualquier tecla para continuar.
Programa realizó system call read(0) llamado con 140726234331039, 139785173327752, 832
Presione cualquier tecla para continuar.
Programa realizó system call pread64(17) llamado con 784, 139785173327806, 784
Presione cualquier tecla para continuar.
Programa realizó system call pread64(17) llamado con 140726234330456, 139785173327806, 32
Presione cualquier tecla para continuar.
Programa realizó system call pread64(17) llamado con 140726234330512, 139785173327806, 68
Presione cualquier tecla para continuar.
Programa realizó system call fstat(5) llamado con 0, 139785173327001, 140726234330720
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 34, 139785173328102, 3
Presione cualquier tecla para continuar.
Programa realizó system call pread64(17) llamado con 784, 139785173327806, 784
Presione cualquier tecla para continuar.
Programa realizó system call pread64(17) llamado con 140726234328976, 139785173327806, 32
Presione cualquier tecla para continuar.
Programa realizó system call pread64(17) llamado con 140726234328944, 139785173327806, 68
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 2050, 139785173328102, 1
Presione cualquier tecla para continuar.
Programa realizó system call mprotect(10) llamado con 0, 139785173328283, 0
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 2066, 139785173328102, 5
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 2066, 139785173328102, 1
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 2066, 139785173328102, 3
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 50, 139785173328102, 3
Presione cualquier tecla para continuar.
Programa realizó system call close(3) llamado con 1879047679, 139785173327243, 0
Presione cualquier tecla para continuar.
Programa realizó system call arch_prctl(158) llamado con 1, 139785173208256, -139785173077616
Presione cualquier tecla para continuar.
Programa realizó system call mprotect(10) llamado con 139785171179840, 139785173328283, 1
Presione cualquier tecla para continuar.
Programa realizó system call mprotect(10) llamado con 0, 139785173328283, 1
Presione cualquier tecla para continuar.
Programa realizó system call mprotect(10) llamado con 0, 139785173328283, 1
Presione cualquier tecla para continuar.
Programa realizó system call munmap(11) llamado con 139785173393760, 139785173328235, 56465935040512
Presione cualquier tecla para continuar.
Programa realizó system call brk(12) llamado con 135168, 139785172173803, 688
Presione cualquier tecla para continuar.
Programa realizó system call brk(12) llamado con 135168, 139785172173803, 139785173058304
Presione cualquier tecla para continuar.
Programa realizó system call openat(257) llamado con 94133897867968, 139785172170332, 524288
Presione cualquier tecla para continuar.
Programa realizó system call fstat(5) llamado con 0, 139785172145801, 140726234333840
Presione cualquier tecla para continuar.
Programa realizó system call fstat(5) llamado con 139785173050528, 139785172145801, 140726234333376
Presione cualquier tecla para continuar.
Programa realizó system call read(0) llamado con 94133897867968, 139785172170600, 4096
Presione cualquier tecla para continuar.
Programa realizó system call lseek(8) llamado con 3432, 139785172148859, 1
Presione cualquier tecla para continuar.
Programa realizó system call read(0) llamado con 94133897867968, 139785172170600, 4096
Presione cualquier tecla para continuar.
Programa realizó system call close(3) llamado con 94133897867968, 139785172169899, 139785173047456
Presione cualquier tecla para continuar.
Programa realizó system call fstat(5) llamado con 139785173050528, 139785172145801, 140726234332208
Presione cualquier tecla para continuar.
La hora es: Mon Apr 26 15:16:05 2021
Programa realizó system call write(1) llamado con 37, 139785172148711, 37
Presione cualquier tecla para continuar.

ID	║ CONT	║ NOMBRE
══════════════════════════
0	║ 3	║ close
1	║ 1	║ write
3	║ 3	║ close
5	║ 5	║ fstat
8	║ 1	║ write
9	║ 7	║ poll
10	║ 4	║ stat
11	║ 1	║ write
12	║ 3	║ close
17	║ 6	║ lstat
21	║ 1	║ write
59	║ 1	║ write
158	║ 2	║ open
257	║ 3	║ close

```
## Caso 3
Ejecución:
`./rastreador -v echo`

Resultado:
```c

Seleccionó opción v
El nombre del programa por ejecutar es: echo
Se ejecutara programa en modo: 1
Programa realizó system call execve(59) llamado con 0, 0, 0
Programa realizó system call brk(12) llamado con 1, 139726272577195, 95
Programa realizó system call arch_prctl(158) llamado con 0, 139726272572245, 139726272569904
Programa realizó system call access(21) llamado con 139726272647520, 139726272580955, 139726272455280
Programa realizó system call openat(257) llamado con 139726272647368, 139726272581320, 524288
Programa realizó system call fstat(5) llamado con 139726272647368, 139726272580761, 140726215175472
Programa realizó system call mmap(9) llamado con 2, 139726272581862, 1
Programa realizó system call close(3) llamado con 139726272647368, 139726272581003, 1
Programa realizó system call openat(257) llamado con 140726215175871, 139726272581320, 524288
Programa realizó system call read(0) llamado con 140726215175871, 139726272581512, 832
Programa realizó system call pread64(17) llamado con 784, 139726272581566, 784
Programa realizó system call pread64(17) llamado con 140726215175288, 139726272581566, 32
Programa realizó system call pread64(17) llamado con 140726215175344, 139726272581566, 68
Programa realizó system call fstat(5) llamado con 0, 139726272580761, 140726215175552
Programa realizó system call mmap(9) llamado con 34, 139726272581862, 3
Programa realizó system call pread64(17) llamado con 784, 139726272581566, 784
Programa realizó system call pread64(17) llamado con 140726215173808, 139726272581566, 32
Programa realizó system call pread64(17) llamado con 140726215173776, 139726272581566, 68
Programa realizó system call mmap(9) llamado con 2050, 139726272581862, 1
Programa realizó system call mprotect(10) llamado con 0, 139726272582043, 0
Programa realizó system call mmap(9) llamado con 2066, 139726272581862, 5
Programa realizó system call mmap(9) llamado con 2066, 139726272581862, 1
Programa realizó system call mmap(9) llamado con 2066, 139726272581862, 3
Programa realizó system call mmap(9) llamado con 50, 139726272581862, 3
Programa realizó system call close(3) llamado con 1879047679, 139726272581003, 0
Programa realizó system call arch_prctl(158) llamado con 1, 139726272462016, -139726272331456
Programa realizó system call mprotect(10) llamado con 139726270433600, 139726272582043, 1
Programa realizó system call mprotect(10) llamado con 0, 139726272582043, 1
Programa realizó system call mprotect(10) llamado con 0, 139726272582043, 1
Programa realizó system call munmap(11) llamado con 139726272647520, 139726272581995, 62268435857408
Programa realizó system call brk(12) llamado con 135168, 139726271427563, 688
Programa realizó system call brk(12) llamado con 135168, 139726271427563, 139726272312064
Programa realizó system call openat(257) llamado con 140726215178096, 139726271424092, 524288
Programa realizó system call fstat(5) llamado con 3, 139726271399561, 139726272304832
Programa realizó system call mmap(9) llamado con 2, 139726271445574, 1
Programa realizó system call close(3) llamado con 3, 139726271423659, 11179
Programa realizó system call fstat(5) llamado con 139726272304288, 139726271399561, 140726215178704

Programa realizó system call write(1) llamado con 1, 139726271402471, 1
Programa realizó system call close(3) llamado con 139726272300704, 139726271423659, 139726272301216
Programa realizó system call close(3) llamado con 139726272300480, 139726271423659, 139726272301216

ID	║ CONT	║ NOMBRE
══════════════════════════
0	║ 1	║ write
1	║ 1	║ write
3	║ 5	║ fstat
5	║ 4	║ stat
9	║ 8	║ lseek
10	║ 4	║ stat
11	║ 1	║ write
12	║ 3	║ close
17	║ 6	║ lstat
21	║ 1	║ write
59	║ 1	║ write
158	║ 2	║ open
257	║ 3	║ close

```

## Caso 4
Ejecución:
`./rastreador -V echo`

Resultado:
```c

Seleccionó opción V
El nombre del programa por ejecutar es: echo
Se ejecutara programa en modo: 2
Programa realizó system call execve(59) llamado con 0, 0, 0
Presione cualquier tecla para continuar.
Programa realizó system call brk(12) llamado con 1, 139808827154091, 95
Presione cualquier tecla para continuar.
Programa realizó system call arch_prctl(158) llamado con 0, 139808827149141, 139808827146800
Presione cualquier tecla para continuar.
Programa realizó system call access(21) llamado con 139808827224416, 139808827157851, 139808827032176
Presione cualquier tecla para continuar.
Programa realizó system call openat(257) llamado con 139808827224264, 139808827158216, 524288
Presione cualquier tecla para continuar.
Programa realizó system call fstat(5) llamado con 139808827224264, 139808827157657, 140732700083744
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 2, 139808827158758, 1
Presione cualquier tecla para continuar.
Programa realizó system call close(3) llamado con 139808827224264, 139808827157899, 1
Presione cualquier tecla para continuar.
Programa realizó system call openat(257) llamado con 140732700084143, 139808827158216, 524288
Presione cualquier tecla para continuar.
Programa realizó system call read(0) llamado con 140732700084143, 139808827158408, 832
Presione cualquier tecla para continuar.
Programa realizó system call pread64(17) llamado con 784, 139808827158462, 784
Presione cualquier tecla para continuar.
Programa realizó system call pread64(17) llamado con 140732700083560, 139808827158462, 32
Presione cualquier tecla para continuar.
Programa realizó system call pread64(17) llamado con 140732700083616, 139808827158462, 68
Presione cualquier tecla para continuar.
Programa realizó system call fstat(5) llamado con 0, 139808827157657, 140732700083824
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 34, 139808827158758, 3
Presione cualquier tecla para continuar.
Programa realizó system call pread64(17) llamado con 784, 139808827158462, 784
Presione cualquier tecla para continuar.
Programa realizó system call pread64(17) llamado con 140732700082080, 139808827158462, 32
Presione cualquier tecla para continuar.
Programa realizó system call pread64(17) llamado con 140732700082048, 139808827158462, 68
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 2050, 139808827158758, 1
Presione cualquier tecla para continuar.
Programa realizó system call mprotect(10) llamado con 0, 139808827158939, 0
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 2066, 139808827158758, 5
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 2066, 139808827158758, 1
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 2066, 139808827158758, 3
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 50, 139808827158758, 3
Presione cualquier tecla para continuar.
Programa realizó system call close(3) llamado con 1879047679, 139808827157899, 0
Presione cualquier tecla para continuar.
Programa realizó system call arch_prctl(158) llamado con 1, 139808827038912, -139808826908352
Presione cualquier tecla para continuar.
Programa realizó system call mprotect(10) llamado con 139808825010496, 139808827158939, 1
Presione cualquier tecla para continuar.
Programa realizó system call mprotect(10) llamado con 0, 139808827158939, 1
Presione cualquier tecla para continuar.
Programa realizó system call mprotect(10) llamado con 0, 139808827158939, 1
Presione cualquier tecla para continuar.
Programa realizó system call munmap(11) llamado con 139808827224416, 139808827158891, 62345745268736
Presione cualquier tecla para continuar.
Programa realizó system call brk(12) llamado con 135168, 139808826004459, 688
Presione cualquier tecla para continuar.
Programa realizó system call brk(12) llamado con 135168, 139808826004459, 139808826888960
Presione cualquier tecla para continuar.
Programa realizó system call openat(257) llamado con 140732700086368, 139808826000988, 524288
Presione cualquier tecla para continuar.
Programa realizó system call fstat(5) llamado con 3, 139808825976457, 139808826881728
Presione cualquier tecla para continuar.
Programa realizó system call mmap(9) llamado con 2, 139808826022470, 1
Presione cualquier tecla para continuar.
Programa realizó system call close(3) llamado con 3, 139808826000555, 11179
Presione cualquier tecla para continuar.
Programa realizó system call fstat(5) llamado con 139808826881184, 139808825976457, 140732700086976
Presione cualquier tecla para continuar.

Programa realizó system call write(1) llamado con 1, 139808825979367, 1
Presione cualquier tecla para continuar.
Programa realizó system call close(3) llamado con 139808826877600, 139808826000555, 139808826878112
Presione cualquier tecla para continuar.
Programa realizó system call close(3) llamado con 139808826877376, 139808826000555, 139808826878112
Presione cualquier tecla para continuar.

ID	║ CONT	║ NOMBRE
══════════════════════════
0	║ 1	║ write
1	║ 1	║ write
3	║ 5	║ fstat
5	║ 4	║ stat
9	║ 8	║ lseek
10	║ 4	║ stat
11	║ 1	║ write
12	║ 3	║ close
17	║ 6	║ lstat
21	║ 1	║ write
59	║ 1	║ write
158	║ 2	║ open
257	║ 3	║ close

```
<br/><br/><br/><br/>
_ end line _

# C25200_TP1

Horario de la Aerolinea: 05:00 inclusive -> 23:00 no incluido.
Informacion del sistema en archivo de texto plano, debe guardarse nuevamente en un archivo despues del horario activo.

Caracteristicas del Vuelo
- Modelo
- Caracteristicas tripulacion
- Fecha con hora (partida y llegada)
- Lugar: salida y destino.
- Duracion
- Asientos (Ocupado, Disponible)
- Estado (Programado, Retrasado, Cancelado, Partió, Aterrizó)

Features del Programa:
1. Ver vuelos
2. Consultar Vuelo ??
3. Cambio de Estado de Vuelo
4. Verificar asientos del Vuelo
5. Hacer Check-In de una persona en un vuelo
6. Carga y Almacenamiento de la info del sistema en un archivo de texto plano.

Ideas:
Organizar vuelos en varios arboles binarios (uno por dia) ordenado por hora

Clases:
- Vuelo
- Asiento ??
- ListaVuelos (clase anidada: Nodo)
- Clases GUI: (ConsultarVuelo, VerificarAsientos, Check-In)
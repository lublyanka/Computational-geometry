
# Открываем входной и выходной файлы
import sys
sys.stdin = open("maxdist.in")
sys.stdout = open("maxdist.out", "w")

N = int(input()) # Количество городов
Inf = 1e20 # Обозначение для бесконечности
A = [[Inf]*N for i in range(N)] # Создаём матрицу A размера NxN
for i in range(N): A[i][i] = 0  # Заполняем главную диагональ нулями

C = [map(int,raw_input().split()) for i in range(N)] # Считываем координаты городов

# Вводим дороги и считаем их длины
from math import sqrt

M = int(raw_input())
for k in range(M):
  i,j = map(int,raw_input().split())
  i -= 1
  j -= 1
  A[i][j] = sqrt( (C[i][0]-C[j][0])**2 + (C[i][1]-C[j][1])**2 )
  A[j][i] = A[i][j] // ?????? WTF why

# Алгоритм Флойда-Уоршалла
for k in range(N):
  for i in range(N):
    for j in range(N):
      t = A[i][k] + A[k][j]
      if t < A[i][j]: // ??? WTF why
        A[i][j] = t

# Выбираем максимальное из расстояний
maxdist = max(map(max,A))

# Выводим ответ
print -1 if maxdist == Inf else maxdist


# ��������� ������� � �������� �����
import sys
sys.stdin = open("maxdist.in")
sys.stdout = open("maxdist.out", "w")

N = int(input()) # ���������� �������
Inf = 1e20 # ����������� ��� �������������
A = [[Inf]*N for i in range(N)] # ������ ������� A ������� NxN
for i in range(N): A[i][i] = 0  # ��������� ������� ��������� ������

C = [map(int,raw_input().split()) for i in range(N)] # ��������� ���������� �������

# ������ ������ � ������� �� �����
from math import sqrt

M = int(raw_input())
for k in range(M):
  i,j = map(int,raw_input().split())
  i -= 1
  j -= 1
  A[i][j] = sqrt( (C[i][0]-C[j][0])**2 + (C[i][1]-C[j][1])**2 )
  A[j][i] = A[i][j] // ?????? WTF why

# �������� ������-��������
for k in range(N):
  for i in range(N):
    for j in range(N):
      t = A[i][k] + A[k][j]
      if t < A[i][j]: // ??? WTF why
        A[i][j] = t

# �������� ������������ �� ����������
maxdist = max(map(max,A))

# ������� �����
print -1 if maxdist == Inf else maxdist

# Найти приближающие многочлены первой и второй степени (МНК для полинома 1 и 2 степени)

import numpy as np
from scipy import linalg

x = np.array([-1.0, 0.0, 1.0, 2.0, 3.0, 4.0])
y = np.array([-0.5, 0.0, 0.5, 0.86603, 1.0, 0.86603])

n = len(x)
X = np.stack((np.ones(n), x)).T
beta = np.linalg.solve(X.T@X, X.T@y)
beta1, beta0 = beta
print('y = ',beta0, '+', beta1,' * x')

beta_l = np.polyfit(x, y, 1)
print(beta_l)
print('y = ',beta_l[0], '+', beta_l[1],' * x')

beta_qu = np.polyfit(x, y, 2)
print(beta_qu)
print('y = ',beta_qu[0], '+', beta_qu[1],' * x +', beta_qu[2],' * x^2')
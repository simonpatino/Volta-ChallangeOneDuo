# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
def generar_presion(altitud_maxima):
  """
  Genera valores de presión atmosférica de 0km hasta 3km y luego de descenso.

  Args:
    altitud_maxima: Altitud máxima a iterar en metros.

  Return:
    Lista de valores de presión atmosférica en hPa.

  Nota: El error del sensor no es incluido en la simulación
  ya que este es de 1hPa, que es alrededor de un metro y
  por lo tanto no relevante para la aplicación actual.
  """

  # Constant definition

  R = 8.31432 # Universal gas
  g0 = 9.80665 # Gravity
  M = 0.0289644 # Molar mass of air

  # Define the pressure at sea level (hPa).
  Pb = 1013.25

  #Define the standard temperature at sea level (K).
  Tb = 288.15

  # Define the temperature lapse rate (K/m).
  Lb = -0.0065

  # Height at the bottom of atmospheric layer (m).
  hb = 0

  # Calculate the pressure at each altitude.
  pressure = []
  for h in range(altitud_maxima):
    pressure.append(Pb * (1 + (Lb / Tb) * (h - hb))**((-g0*M) / (R*Lb)))

  return pressure

ys = generar_presion(3000)
xs = [x for x in range(3000)]

plt.plot(xs, ys)
plt.show()
plt.close()

#Tentative ejection pressure:

#701.0854 hpa

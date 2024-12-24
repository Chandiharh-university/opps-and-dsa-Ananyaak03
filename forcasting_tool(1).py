# -*- coding: utf-8 -*-
"""Forcasting tool(1)

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1UReyddSEx1LES1f5rIe3ziyFoQ2G3xl2
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error

# Load your dataset
# Example: df = pd.read_csv('energy_consumption.csv')
# Synthetic dataset
date_rng = pd.date_range(start='1/1/2020', end='12/31/2023', freq='D')
energy_data = np.random.randint(200, 500, size=(len(date_rng)))
df = pd.DataFrame({'date': date_rng, 'energy_usage': energy_data})
df['date'] = pd.to_datetime(df['date'])
df.set_index('date', inplace=True)

# Display first few rows
print(df.head())

plt.figure(figsize=(12, 6))
plt.plot(df.index, df['energy_usage'], label='Daily Energy Usage')
plt.xlabel('Date')
plt.ylabel('Energy Usage (kWh)')
plt.title('Energy Usage Over Time')
plt.legend()
plt.show()

# Create lag features for forecasting
df['lag_1'] = df['energy_usage'].shift(1)
df.dropna(inplace=True)

# Split data into features and target
X = df[['lag_1']]
y = df['energy_usage']

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

model = RandomForestRegressor(n_estimators=100, random_state=42)
model.fit(X_train, y_train)

y_pred = model.predict(X_test)
mae = mean_absolute_error(y_test, y_pred)
print(f"Mean Absolute Error: {mae:.2f}")

# Plot actual vs. predicted
plt.figure(figsize=(10, 5))
plt.plot(y_test.values[:50], label='Actual', marker='o')
plt.plot(y_pred[:50], label='Predicted', marker='x')
plt.legend()
plt.title('Actual vs Predicted Energy Usage')
plt.show()

# Generate future predictions
future_dates = pd.date_range(start='2024-01-01', end='2024-01-10', freq='D')
future_usage = []

last_value = df['energy_usage'].iloc[-1]
for _ in range(len(future_dates)):
    pred = model.predict([[last_value]])
    future_usage.append(pred[0])
    last_value = pred[0]

# Create DataFrame for future predictions
future_df = pd.DataFrame({'date': future_dates, 'predicted_energy_usage': future_usage})
print(future_df)

# Plot future predictions
plt.figure(figsize=(10, 5))
plt.plot(future_df['date'], future_df['predicted_energy_usage'], label='Predicted Future Usage', marker='o')
plt.title('Future Energy Usage Prediction')
plt.xlabel('Date')
plt.ylabel('Energy Usage (kWh)')
plt.legend()
plt.show()

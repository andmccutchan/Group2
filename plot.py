import pandas as pd
import matplotlib.pyplot as plt

# Load data from CSV
file_path = "hashmap_slot_distribution.csv"  # Replace with your file path
data = pd.read_csv(file_path)

# Unique sizes in the dataset
sizes = sorted(data["Size"].unique())

# Plot slot distributions for each size
plt.figure(figsize=(10, 6))

for size in sizes:
    subset = data[data["Size"] == size]
    plt.plot(subset["Slot"], subset["Count"], label=f"Size {size}", color="black", alpha=0.7)

plt.title("Slot Distribution for HashMap Sizes (100 to 1,000,000)")
plt.xlabel("Slot")
plt.ylabel("Count of Elements")
plt.grid(True, linestyle="--", alpha=0.6)
plt.tight_layout()

plt.show()

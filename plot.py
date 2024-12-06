# import pandas as pd
# import matplotlib.pyplot as plt

# # Load data from CSV
# file_path = "hashset_slot_distribution.csv"  # Replace with your file path
# data = pd.read_csv(file_path)

# # Unique sizes in the dataset
# sizes = sorted(data["Size"].unique())

# # Plot slot distributions for each size
# plt.figure(figsize=(10, 6))

# for size in sizes:
#     subset = data[data["Size"] == size]
#     plt.plot(subset["Slot"], subset["Count"], label=f"Size {size}", color="black", alpha=0.7)
    
#     plt.show()

#     plt.title("Slot Distribution for HashMap Size " + str(size))
#     plt.xlabel("Slot")
#     plt.ylabel("Count of Elements")
#     lt.grid(True, linestyle="--", alpha=0.6)
#     plt.tight_layout()


import pandas as pd
import matplotlib.pyplot as plt

# Load data from CSV
file_path = "hashset_slot_distribution.csv"  # Replace with your file path
data = pd.read_csv(file_path)

# Unique sizes in the dataset
sizes = sorted(data["Size"].unique())

# Plot slot distributions for each size as bar graphs
for size in sizes:
    subset = data[data["Size"] == size]
    
    # Create a new figure for each size
    plt.figure(figsize=(10, 6))
    
    # Plot the data as a bar graph
    plt.bar(subset["Slot"], subset["Count"], color="blue", alpha=0.7)
    
    # Customize the plot
    plt.title(f"Slot Distribution for HashMap Size {size}")
    plt.xlabel("Slot")
    plt.ylabel("Count of Elements")
    plt.grid(axis='y', linestyle="--", alpha=0.6)  # Grid only for Y-axis
    plt.tight_layout()
    
    # Show the plot
    plt.show()


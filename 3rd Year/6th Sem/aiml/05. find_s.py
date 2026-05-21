import pandas as pd

training_data = {
    "attribute_names": ["Citations", "Size", "In Library", "Price", "Editions", "Buy"],
    "training_attributes": [
        ["some", "small", "no", "affordable", "many"],
        ["many", "big", "no", "expensive", "one"],
        ["some", "big", "always", "expensive", "few"],
        ["many", "medium", "no", "expensive", "many"],
        ["many", "small", "no", "affordable", "many"],
    ],
    "target_value": ["no", "yes", "no", "yes", "yes"],
}
training_df = pd.DataFrame(
    data=training_data["training_attributes"],
    columns=training_data["attribute_names"][:-1],
    index=pd.RangeIndex(1, 6),
)
training_df["Buy"] = training_data["target_value"]

phi = "\u036a"
hypothesis = [phi for i in range(len(training_data["attribute_names"]) - 1)]
print("Training data:")
print(training_df)
print("\nInitial hypothesis:", hypothesis)
print("\nTraining using Find-S...")

for i in range(len(training_data["target_value"])):
    if training_data["target_value"][i] == "yes":
        data = training_data["training_attributes"][i]
        print(
            "The example is:",
            data,
            ". It is positive example and hence used for training.",
        )
        for j in range(len(hypothesis)):
            if hypothesis[j] == phi:
                hypothesis[j] = data[j]
            elif hypothesis[j] != data[j]:
                hypothesis[j] = "?"
    else:
        print(
            "The example is:",
            training_data["training_attributes"][i],
            ". It is negative example and hence ignored.",
        )
    print(f"Hypothesis after using example {i+1} is:", hypothesis)

print("\nFinal hypothesis:", hypothesis)

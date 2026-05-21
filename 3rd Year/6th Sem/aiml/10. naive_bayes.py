import pandas as pd
import numpy as np

data = pd.read_excel("./customer.xlsx", index_col=0, dtype=str)
print(data)


def naive_bayes(x):
    p_yes = round(data.buys_computer.value_counts()["yes"] / len(data), 3)
    p_no = round(data.buys_computer.value_counts()["no"] / len(data), 3)

    yes_rows = data.buys_computer == "yes"
    no_rows = data.buys_computer == "no"

    p_age_yes = round(
        len(data[(yes_rows) & (data.age == x["age"])]) / len(data[yes_rows]), 3
    )
    p_age_no = round(
        len(data[(no_rows) & (data.age == x["age"])]) / len(data[no_rows]), 3
    )
    p_income_yes = round(
        len(data[(yes_rows) & (data.income == x["income"])]) / len(data[yes_rows]), 3
    )
    p_income_no = round(
        len(data[(no_rows) & (data.income == x["income"])]) / len(data[no_rows]), 3
    )
    p_student_yes = round(
        len(data[(yes_rows) & (data.student == x["student"])]) / len(data[yes_rows]), 3
    )
    p_student_no = round(
        len(data[(no_rows) & (data.student == x["student"])]) / len(data[no_rows]), 3
    )
    p_credit_rating_yes = round(
        len(data[(yes_rows) & (data.credit_rating == x["credit_rating"])])
        / len(data[yes_rows]),
        3,
    )
    p_credit_rating_no = round(
        len(data[(no_rows) & (data.credit_rating == x["credit_rating"])])
        / len(data[no_rows]),
        3,
    )
    p_buys_yes = round(
        p_age_yes * p_income_yes * p_student_yes * p_credit_rating_yes * p_yes, 3
    )
    p_buys_no = round(
        p_age_no * p_income_no * p_student_no * p_credit_rating_no * p_no, 3
    )

    print(f'P(age="{x["age"]}"|buys_computer="yes") = {p_age_yes}')
    print(f'P(age="{x["age"]}"|buys_computer="no") = {p_age_no}')
    print(f'P(income="{x["income"]}"|buys_computer="yes") = {p_income_yes}')
    print(f'P(income="{x["income"]}"|buys_computer="no") = {p_income_no}')
    print(f'P(student="{x["student"]}"|buys_computer="yes") = {p_student_yes}')
    print(f'P(student="{x["student"]}"|buys_computer="no") = {p_student_no}')
    print(
        f'P(credit_rating="{x["credit_rating"]}"|buys_computer="yes") = {p_credit_rating_yes}'
    )
    print(
        f'P(credit_rating="{x["credit_rating"]}"|buys_computer="no") = {p_credit_rating_no}'
    )
    print(f'P(buys_computer="yes") = {p_yes}')
    print(f'P(buys_computer="no") = {p_no}')
    print(f'P(buys_computer="yes"|X) = {p_buys_yes}')
    print(f'P(buys_computer="no"|X) = {p_buys_no}')
    print(f"Person:{x}")
    if p_buys_yes > p_buys_no:
        print("The person will buy computer")
    else:
        print("The person will not buy computer")


x = {"age": "<=30", "income": "medium", "student": "yes", "credit_rating": "fair"}
naive_bayes(x)
print("-" * 50)
x = {"age": "<=30", "income": "low", "student": "no", "credit_rating": "fair"}
naive_bayes(x)

# LP2 Practical
# Expert System for Hospitals and Medical Facilities

print("Medical Expert System Started")
print("Type 'exit' to stop\n")

while True:
    problem = input("Enter Problem: ").lower()

    if problem == "fever":
        print("Advice: Take Paracetamol and Rest")

    elif problem == "cold":
        print("Advice: Drink Warm Water")

    elif problem == "cough":
        print("Advice: Use Cough Syrup")

    elif problem == "headache":
        print("Advice: Take Proper Sleep")

    elif problem == "stomach pain":
        print("Advice: Eat Light Food")

    elif problem == "vomiting":
        print("Advice: Drink More Water")

    elif problem == "body pain":
        print("Advice: Take Rest")

    elif problem == "exit":
        print("System Stopped")
        break

    else:
        print("Advice: Consult Doctor")
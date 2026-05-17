#LP2 Practical
# Customer Support Chatbot
print("Customer Support Chatbot Started")
print("Type 'bye' to stop\n")
while True:
    user = input("Customer: ")
    if user == "hello":
        print("Bot: Welcome to Customer Support")
    elif user == "product":
        print("Bot: We sell electronic products")
    elif user == "price":
        print("Bot: Prices start from 1000 rupees")
    elif user == "delivery":
        print("Bot: Delivery takes 3 days")
    elif user == "bye":
        print("Bot: Thank you for visiting")
        break
    else:
        print("Bot: Please ask valid question")
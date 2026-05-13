from openai import OpenAI

# Cerebras API setup
client = OpenAI(
    api_key="YOUR_CEREBRAS_API_KEY",
    base_url="https://api.cerebras.ai/v1"
)

def chatbot():

    print("===================================")
    print(" Welcome to Cerebras AI Chatbot 🤖")
    print(" Type 'exit' to stop")
    print("===================================")

    while True:

        user_input = input("\nYou: ")

        if user_input.lower() == "exit":
            print("Chatbot: Goodbye 👋")
            break

        try:

            response = client.chat.completions.create(
                model="llama3.1-8b",   # Cerebras model
                messages=[
                    {
                        "role": "system",
                        "content": "You are a helpful assistant."
                    },
                    {
                        "role": "user",
                        "content": user_input
                    }
                ]
            )

            reply = response.choices[0].message.content

            print("\nChatbot:", reply)

        except Exception as e:
            print("Error:", e)

# Run chatbot
chatbot()
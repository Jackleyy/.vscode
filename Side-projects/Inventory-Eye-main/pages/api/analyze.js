// pages/api/analyze.js
import OpenAI from "openai";

const openai = new OpenAI({
  apiKey: process.env.NEXT_PUBLIC_OPENAI_API_KEY,
});

async function callGPT4API(image) {

    console.log('HIT OPENAI API')

  try {
    const response = await openai.chat.completions.create({
      model: "gpt-4o-2024-08-06",
      messages: [
        {
          role: "user",
          content: [
            {
              type: "image_url",
              image_url: {
                url: image, // Assuming image is a base64 encoded URL
              },
            },
            {
              type: "text",
              text: 'Return ONLY A JSON of the objects on the table or shelf like {"apple": 3, "banana": 5}. You can group items that are pretty much the same in the same key',
            },
          ],
        },
        {
          role: "assistant",
          content: [
            {
              type: "text",
              text: "Hey there! What can I help you with today?",
            },
          ],
        },
      ],
      temperature: 1,
      max_tokens: 2048,
      top_p: 1,
      frequency_penalty: 0,
      presence_penalty: 0,
      response_format: {
        type: "text",
      },
    });
    console.log('HIT OPENAI API')
    console.log(response.choices[0].message.content)
    return response.choices[0].message.content;
  } catch (error) {
    console.error('Error fetching analysis:', error);
    return "Analysis not available yet";
  }
}

export default async function handler(req, res) {
  if (req.method === 'POST') {
    const { image } = req.body;
    const analysis = await callGPT4API(image);
    res.status(200).json({ analysis });
  } else {
    res.status(405).json({ message: 'Method Not Allowed' });
  }
}
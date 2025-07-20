// index.jsx
import React, { useState, useEffect } from "react";
import WebCam from '../components/WebCam';
import DynamicBarGraph from '../components/graph';

async function callGPT4API(image) {
  try {
    const response = await fetch('/api/analyze', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ image }),
    });

    const data = await response.json();
    return data.analysis;
  } catch (error) {
    console.error('Error fetching analysis:', error);
    return "Error";
  }
}

export default function Home() {
  const [image, setImage] = useState(null);
  const [analysis, setAnalysis] = useState("");

  useEffect(() => {
    const fetchAnalysis = async () => {
      // return
      if (image) {
        setAnalysis("Pending");
        var analysisResult = await callGPT4API(image);

        // it looks like: ```json { "sunglasses": 1, "pen": 1 } ```
        // remove the backticks and the json keyword and parse the string to an object
        analysisResult = JSON.parse(analysisResult.replace('json', '').replace(/`/g, ''));

        setAnalysis(analysisResult);
      }
    };

    fetchAnalysis();
  }, [image]);

  return (
    <div className="flex flex-col items-center justify-center min-h-screen py-4 bg-gray-100">
      <div className="pt-10 flex w-full  flex-row items-center justify-evenly">
        <WebCam setImage={setImage} />

        {image && (
          <div className="mt-8 flex flex-col items-center">
            <h3 className="text-xl font-semibold mb-4">Captured Image:</h3>
            <img src={image} alt="Captured" className="w-64 h-auto rounded-lg shadow-md" />
            {/* <p className="mt-4 text-center text-lg">Analysis: {JSON.stringify(analysis)}</p> */}
          </div>
        )}
      </div>
      {analysis && analysis == "Pending" && (
        <div className="mt-8 text-2xl font-semibold text-center">Analyzing...</div>
      )}
      {analysis&& (
        <DynamicBarGraph data={analysis} setData={setAnalysis} />
      )}
    </div>
  );
}

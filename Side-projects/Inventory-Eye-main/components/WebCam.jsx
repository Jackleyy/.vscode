// components/WebCam.jsx
import React, { useRef } from 'react';
import Webcam from 'react-webcam';

const WebCam = ({ setImage }) => {
  const webcamRef = useRef(null);

  const videoConstraints = {
    width: 640,
    height: 480,
    facingMode: 'user',
  };

  const capture = () => {
    if (webcamRef.current) {
      const screenshot = webcamRef.current.getScreenshot();
      setImage(screenshot);
    }
  };

  return (
    <div className="flex flex-col items-center">
      <h2 className="text-2xl font-semibold mb-6">Live Stream</h2>
      <div className="w-full max-w-md">
        <Webcam
          audio={false}
          ref={webcamRef}
          screenshotFormat="image/jpeg"
          videoConstraints={videoConstraints}
          className="w-full rounded-lg shadow-lg"
        />
      </div>
      <button
        onClick={capture}
        className="mt-6 px-6 py-2 bg-blue-600 text-white rounded-md hover:bg-blue-700 focus:outline-none"
      >
        Capture Photo
      </button>
    </div>
  );
};

export default WebCam;

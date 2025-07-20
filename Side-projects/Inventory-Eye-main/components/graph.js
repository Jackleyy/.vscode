// DynamicBarGraph.js
import React, { useEffect } from 'react';

const DynamicBarGraph = ({ data, setData }) => {


    // Array of colors corresponding to popular fruits
    const colors = ["#8FB9A8", "#FFDD94", "#FFABAB", "#FFC3A0", "#C3AED6", "#FFB7C5", "#A2D5F2", "#B5EAD7", "#E2F0CB", "#FFDAC1"];

    // Convert data object into an array format suitable for rendering
    function transformData(dataObject) {
        return Object.keys(dataObject).map(key => ({
            name: key,
            count: dataObject[key]
        }));
    }

    // Function to render the bar chart
    function renderBarChart() {
        const chartContainer = document.getElementById('bar-chart');
        const yAxisContainer = document.getElementById('y-axis');
        chartContainer.innerHTML = '';  // Clear the container
        yAxisContainer.innerHTML = '';  // Clear the Y-axis container

        const dataArray = transformData(data); // Convert data to array format

        // Determine max and min counts for scaling
        const maxCount = Math.max(...dataArray.map(item => item.count), 1); // Ensure maxCount is at least 1
        const minCount = 0; // Start from 0 for better readability
        const step = Math.ceil((maxCount - minCount) / maxCount   ); // Determine the interval for the y-axis
        
        // const max_data_count = Math.max(...dataArray.map(item => item.count));

        // Render Y-axis labels
        for (let i = 0; i <= maxCount; i++) {
            const label = document.createElement('div');
            label.textContent = minCount + i * step;
            yAxisContainer.appendChild(label);
        }

        // Render bars
        dataArray.forEach((item, index) => {
            const bar = document.createElement('div');
            bar.className = 'bar';
            bar.style.height = `${(item.count / maxCount) * 100}%`;
            bar.style.backgroundColor = colors[index % colors.length];  // Assign color based on index
            bar.innerHTML = `<span>${item.name}: ${item.count}</span>`;
            chartContainer.appendChild(bar);
        });
    }


    useEffect(() => {
        renderBarChart();
    }, [data]);

    return (
        <div style={{ padding: '20px', width: '100%' }}>
            <div id="chart-title">Dynamic Bar Graph</div>
            <div id="bar-chart-container" style={{ width: '100%', height: '400px', display: 'flex' }}>
                <div id="y-axis"></div>
                <div id="bar-chart"></div>
            </div>
            {/* <button onClick={addRandomData}>Add Random Data</button> */}
        </div>
    );
};

export default DynamicBarGraph;

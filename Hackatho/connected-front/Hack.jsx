import React, { useState, useEffect } from 'react';
import './Hack.css'; {/* Import our CSS */}






{/*this helps rng the location of the boxes */}
<div
  key={card} 
  className="card" 
  style={{
    position: 'absolute',  
    left: positions[index]?.x || 0, 
    top: positions[index]?.y || 0, 
            
  }}
>
  {item} 
</div>
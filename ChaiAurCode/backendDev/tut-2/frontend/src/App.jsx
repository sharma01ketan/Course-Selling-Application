import React, { useEffect } from 'react'
import { useState } from 'react'

const App = () => {
  const [jokes,setJokes] = useState([])

  useEffect(()=>{
    axios.get('/api/jokes')
    .then((res)=>{
      setJokes(res.data)
    }).catch((err)=>{
      console.log(err)
    })
  })



  return (
    <>
      <h1>Chai and Full Stack</h1>
      <p>JOKES {jokes.length}</p>
      {
        jokes.map((joke,index)=>{
          <div key={joke.id}>
            <h3>{joke.question}</h3>
            <p>{joke.answer}</p>
          </div>
        })
      }
    </>
  )
}

export default App
import express from 'express'

const app = express()

app.get('/',(req,res)=>{
    res.send('Server is ready')
})

app.get('/api/jokes',(req,res)=>{
    const jokes = [
        {
          id: 1,
          question: "Why don't scientists trust atoms?",
          answer: "Because they make up everything!"
        },
        {
          id: 2,
          question: "What do you call fake spaghetti?",
          answer: "An impasta!"
        },
        {
          id: 3,
          question: "Why did the scarecrow win an award?",
          answer: "Because he was outstanding in his field!"
        },
        {
          id: 4,
          question: "What do you get when you cross a snowman and a vampire?",
          answer: "Frostbite!"
        },
        {
          id: 5,
          question: "Why don't skeletons fight each other?",
          answer: "They don't have the guts!"
        }
      ];
      res.send(jokes)
      console.log(jokes);
      
})

const port = process.env.PORT || 3000

app.listen(port, ()=>{
    console.log(`Serve at http://localhost:${port}`)
})
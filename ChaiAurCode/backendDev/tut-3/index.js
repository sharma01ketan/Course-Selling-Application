import mongoose from "mongoose";

const todoSchema = new mongoose.Schema({
    content: {
        type: String, 
        required: true,
    },
    complete: {
        type: Boolean,
        default: false
    },
    createdBy: {
        type: mongoose.Schema.Types.ObjectId,
        ref: 'User'
    }
},{timeseries:true})

export const SubTodo = mongoose.model('Todo',todoSchema)
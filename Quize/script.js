const quizData = [
    {
        question: '1.Where does business intelligence come from?',
        options: ['Information technology', 'Information', 'Customer knowledge', 'Competitor knowledge'],
        answer: 'Information',
    },
    {
        question: '2.What is business intelligence knowledge about?',
        options: ['Customers ', 'Competitors', 'Partners', 'All of the above'],
        answer: 'All of the above',
    },
    {
        question: '3.Which of the following tools is used to help an organization build and use business intelligence?',
        options: ['A) Data warehouse',
            'B) Data-mining tools',
            'C) Database management systems',
            'D) All of the above'],
        answer: 'All of the above',
    },
    {
        question: '4.What are databases that support OLTP?',
        options: ['OLAP',
            'B) OLTP',
            'C) A database',
            'D) An operational database'],
        answer: 'An operational database',
    },
    {
        question: '5.What is the manipulation of information to support decision making?',
        options: ['A) OLAP',
            'B) OLTP',
            'C) A database',
            'D) An operational database'],
        answer: ' OLAP',
    },
    {
        question: '6.	What is the gathering of input information, processing that information, and updating existing information to reflect the gathered and processed information?',
        options: ['A) OLAP',
            'B) OLTP',
            'C) A database',
            'D) An operational database'],
        answer: 'OLTP',
    },
    {
        question: '7.	What do databases and DBMSs directly support?',
        options: [
            'A) OLDP',
            'B) OLTP',
            'C) Databases',
            'D) Operational databases',
        ],
        answer: 'OLTP',
    },
    {
        question: '8.	What do data warehouses support?',
        options: [
            'A) OLAP',
            'B) OLTP',
            'C) OLAP and OLTP',
            'D) Operational databases',
        ],
        answer: 'OLTP',
    },
    {
        question: '9.	Which of the following is inaccurate in reference to a database?',
        options: [
            'A) A collection of information',
            'B) Organized by logical structure',
            'C) Accessed by physical structure',
            'D) None of the above',
        ],
        answer: 'Accessed by physical structure',
    },
    {
        question: '10.	Which data administration function periodically backs up information contained in a database?',
        options: [
            'A) Concurrency control facilities',
            'B) Reorganization facilities',
            'C) Backup and recovery facilities',
            'D) Security management facilities',
        ],
        answer: 'Backup and recovery facilities',
    },
];

const quizContainer = document.getElementById('quiz');
const resultContainer = document.getElementById('result');
const submitButton = document.getElementById('submit');
const retryButton = document.getElementById('retry');
const showAnswerButton = document.getElementById('showAnswer');

let currentQuestion = 0;
let score = 0;
let incorrectAnswers = [];

function shuffleArray(array) {
    for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    }
}

function displayQuestion() {
    const questionData = quizData[currentQuestion];

    const questionElement = document.createElement('div');
    questionElement.className = 'question';
    questionElement.innerHTML = questionData.question;

    const optionsElement = document.createElement('div');
    optionsElement.className = 'options';

    const shuffledOptions = [...questionData.options];
    shuffleArray(shuffledOptions);

    for (let i = 0; i < shuffledOptions.length; i++) {
        const option = document.createElement('label');
        option.className = 'option';

        const radio = document.createElement('input');
        radio.type = 'radio';
        radio.name = 'quiz';
        radio.value = shuffledOptions[i];

        const optionText = document.createTextNode(shuffledOptions[i]);

        option.appendChild(radio);
        option.appendChild(optionText);
        optionsElement.appendChild(option);
    }

    quizContainer.innerHTML = '';
    quizContainer.appendChild(questionElement);
    quizContainer.appendChild(optionsElement);
}

function checkAnswer() {
    const selectedOption = document.querySelector('input[name="quiz"]:checked');
    if (selectedOption) {
        const answer = selectedOption.value;
        if (answer === quizData[currentQuestion].answer) {
            score++;
        } else {
            incorrectAnswers.push({
                question: quizData[currentQuestion].question,
                incorrectAnswer: answer,
                correctAnswer: quizData[currentQuestion].answer,
            });
        }
        currentQuestion++;
        selectedOption.checked = false;
        if (currentQuestion < quizData.length) {
            displayQuestion();
        } else {
            displayResult();
        }
    }
}

function displayResult() {
    quizContainer.style.display = 'none';
    submitButton.style.display = 'none';
    retryButton.style.display = 'inline-block';
    showAnswerButton.style.display = 'inline-block';
    resultContainer.innerHTML = `You scored ${score} out of ${quizData.length}!`;
}

function retryQuiz() {
    currentQuestion = 0;
    score = 0;
    incorrectAnswers = [];
    quizContainer.style.display = 'block';
    submitButton.style.display = 'inline-block';
    retryButton.style.display = 'none';
    showAnswerButton.style.display = 'none';
    resultContainer.innerHTML = '';
    displayQuestion();
}

function showAnswer() {
    quizContainer.style.display = 'none';
    submitButton.style.display = 'none';
    retryButton.style.display = 'inline-block';
    showAnswerButton.style.display = 'none';

    let incorrectAnswersHtml = '';
    for (let i = 0; i < incorrectAnswers.length; i++) {
        incorrectAnswersHtml += `
        <p>
          <strong>Question:</strong> ${incorrectAnswers[i].question}<br>
          <strong>Your Answer:</strong> ${incorrectAnswers[i].incorrectAnswer}<br>
          <strong>Correct Answer:</strong> ${incorrectAnswers[i].correctAnswer}
        </p>
      `;
    }

    resultContainer.innerHTML = `
      <p>You scored ${score} out of ${quizData.length}!</p>
      <p>Incorrect Answers:</p>
      ${incorrectAnswersHtml}
    `;
}

submitButton.addEventListener('click', checkAnswer);
retryButton.addEventListener('click', retryQuiz);
showAnswerButton.addEventListener('click', showAnswer);

displayQuestion();
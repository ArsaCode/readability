sentences = 0
words = 0
letters = 0


#Hello ! This is the readability software made for the Problem Set 6 of CS50's Introduction to Computer Science course.
#
#The user should input a text (a part of a book for example, or even a whole book).
#
#The software works as follows :
#
#1 . Get the users input
#2 . Count the total number of letters in the text
#3 . Count the total number of words in the text
#4 . Count the total number of sentences in the text
#5 . Calculates the average of total number of letters per 100 words and total number of sentences per 100 words
#6 . Calculates the readability with the Coleman-Liau's index
#7 . Display the U.S Grade readability for the user (outputs possible : "Before Grade 1, Grade 1 to Grade 16, Grade 16+").
#
#Feel free to send any suggestions at contact@arsadevs.com 


def main():
    getText()
    calculateReadability(sentences, words, letters)
    return 0


def getText():
    global sentences
    global words
    global letters
    text = str(input("Text: "))
    for i in text:
        if i.isalpha():
            letters += 1
    words = text.count(" ") + 1
    sentences = text.count(".") + text.count("!") + text.count("?")
    return 0


def calculateReadability(s, w, l):
    avgL = 0
    avgS = 0
    index = 0
    grade = 0
    avgL = letters * 100 / words
    avgS = sentences * 100 / words
    index = 0.0588 * avgL - 0.296 * avgS - 15.8
    grade = int(round(index))
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade: {grade}")
    return 0


main()
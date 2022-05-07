﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;

namespace CodeQualityChecker
{
    class Tester
    {
        //List of file names
        private readonly List<CodeFile> fileList;
        //List of arrays of file contents separated by line
        //private Tuple<List<string>,List<string[]>> fileListContent;
        

        public Tester(List<CodeFile> fileList)
        {
            this.fileList = fileList;
        }

        public List<CodeFile> RunTests() 
        {
            InitializeFileListContent();
            CheckSpaces();
            EqualityOperatorCheck();
            
            return fileList;
        }
        
        /**
         * Accesses each file and turns the file contents into an array where each line is one string
         */
        public void InitializeFileListContent()
        {
            foreach (CodeFile file in fileList){
                string[] textFileContent;
                textFileContent = File.ReadAllLines(file.FileName, Encoding.UTF8);
                file.FileContent = textFileContent;
            }
        }
        public void CheckSpaces()
        {
            
            foreach (CodeFile file in fileList)
            {
                Console.WriteLine(file.FileName);
                
                file.FileIndentations = CheckSpacesHelper(file.FileContent);


            }
        }

        /**
         * Helper function for CheckSpaces() to more easily iterate through each file
         */
        private int[] CheckSpacesHelper(string[] fileContent)
        {
            int[] indentList = new int[fileContent.Length];
            int spaceCount = 0;
            int lineNum = 1;
            foreach (string line in fileContent)
            {
                spaceCount = line.TakeWhile(Char.IsWhiteSpace).Count();
                indentList.Append(spaceCount);
                //Console.WriteLine(lineNum + ": " + spaceCount);
                lineNum++;
            }
            
            return indentList;
        }

        /**
         * Checks line by line if the code contains a conditional or loop statement using comparisons as well as incorrect = operators.
         * It then through those comparisons to see which ones act more like a variable declaration.
         */
        public void EqualityOperatorCheck()
        {
            //This pattern checks for all kinds of comparisons which may happen within conditional or loop statements,
                //but also including an accidental variable declaration in the form of "=" to be processed later
            string pattern = @"\((?>(?![<>=]=|!=|[<>]).)*?(?:[<>=]=|=|!=|[<>])(?>(?![<>=]=|!=|[<>]).)*?\)";
            
            Regex r = new Regex(pattern, RegexOptions.IgnoreCase);
            string errorPattern = @"\((?>(?![<>=]=|!=|[<>]).)*?(?=)(?>(?![<>=]=|!=|[<>]).)*?\)";
            Regex e = new Regex(errorPattern, RegexOptions.IgnoreCase);
            int lineNumber;
            foreach(CodeFile file in fileList)
            {
                Console.WriteLine(file.FileName);
                lineNumber = 0;
                foreach (string text in file.FileContent)
                {
                    Console.WriteLine(file.FileContent[lineNumber]);
                    //Matches with lines that use comparison operators
                    Match m = r.Match(text);
                    if (m.Success)
                    {
                        Match errorMatch = e.Match(text);
                        if (errorMatch.Success)
                        {
                            Console.WriteLine(lineNumber + " True: ");
                            file.ComparisonStatements.Add(new Tuple<int, bool>(lineNumber, true));
                            
                        }
                        else
                        {
                            Console.WriteLine(lineNumber + " False " );
                            file.ComparisonStatements.Add(new Tuple<int, bool>(lineNumber, false));
                            
                        }
                    }
                    
                    lineNumber++;
                }
            }
        }  

        public void SemicolonCheck()
        {
            string pattern = @";([^\s|/])";
            Regex r = new Regex(pattern, RegexOptions.IgnoreCase);
            int lineNumber;

            foreach(CodeFile file in fileList)
            {
                lineNumber = 0;
                foreach(string text in file.FileContent)
                {
                    Match m = r.Match(text);
                    if (m.Success)
                    {
                        file.SemicolonErrors.Add(lineNumber);
                    }
                    lineNumber++;
                }
            }
        }
        
        
        
        
        public void MethodFinder()
        {

        }
    }


}

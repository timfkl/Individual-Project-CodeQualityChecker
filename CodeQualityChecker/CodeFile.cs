using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeQualityChecker
{
    class CodeFile
    {

        private string _fileName;
        private string[] _fileContent;
        private int[] _fileIndentations;

        public CodeFile(string fileName)
        {
            FileName = fileName;
        }

        public string FileName { get => _fileName; set => _fileName = value; }
        public string[] FileContent { get => _fileContent; set => _fileContent = value; }
        public int[] FileIndentations { get => _fileIndentations; set => _fileIndentations = value; }
    }
}

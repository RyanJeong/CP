package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	"sync"
)

type StringsCollection interface {
	AddString(s string)
	GetAllStrings() []string
}


// NewStringsCollection 함수가 StringsCollection 의 구현체를 생성하여 리턴해야 합니다.
// StringsCollection 인터페이스를 구현해 주세요
func NewStringsCollection() StringsCollection {
    return nil
}

func main() {
	writer, err := os.Create(os.Getenv("OUTPUT_PATH"))
	mustOK(err)
	defer func() { _ = writer.Close() }()

	stringsCollection := NewStringsCollection()

	reader := bufio.NewReaderSize(os.Stdin, 16*1024*1024)
	goroutinesCount := mustParseInt(mustReadLine(reader))

	var wg sync.WaitGroup
	for i := 0; i < goroutinesCount; i++ {
		stringsCount := mustParseInt(mustReadLine(reader))
		wg.Add(1)
		go func(goroutineName string, stringsCount int) {
			defer wg.Done()

			for j := 0; j < stringsCount; j++ {
				stringsCollection.AddString(goroutineName + "_" + strconv.Itoa(j+1))
			}
		}(strconv.Itoa(i+1), stringsCount)
	}
	wg.Wait()

	allStrings := stringsCollection.GetAllStrings()
	_, _ = fmt.Fprintln(writer, len(allStrings))

	uniqueStringsCount := countUniqueStrings(allStrings)
	_, _ = fmt.Fprintln(writer, uniqueStringsCount)
}

func mustReadLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}
	return strings.TrimRight(string(str), "\r\n")
}

func mustOK(err error) {
	if err != nil {
		panic(err)
	}
}

func mustParseInt(s string) int {
	i, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return i
}

func countUniqueStrings(ss []string) int {
	m := make(map[string]struct{}, len(ss))
	for _, s := range ss {
		m[s] = struct{}{}
	}
	return len(m)
}

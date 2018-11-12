package com.company;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {

    private static void show(List<String> a) {
        a.forEach(System.out::println);
    }

    public static void main(String[] args) {
        List<String> words = Arrays.asList("hi", "hello", "be", "apple", "banana");
        words.forEach(x -> System.out.println(" " + x));
        words.forEach(System.out::println);
        List<String> excitingWords = words.stream().map(s -> s + "!").collect(Collectors.toList());
        excitingWords.forEach(System.out::println);
        List<String> eyeWords = words.stream().map(s -> s.replace("i", "eye")).collect(Collectors.toList());
        eyeWords.forEach(System.out::println);
        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5, 6);
        Double average = numbers.stream().collect(Collectors.averagingInt(item -> item));
        System.out.println(average);
        List<String> upperCaseWords = words.stream().map(String::toUpperCase).collect(Collectors.toList());
        upperCaseWords.forEach(System.out::println);
        List<String> shortWords = words.stream().filter(s -> s.length() < 4).collect(Collectors.toList());
        show(shortWords);

    }
}
